//
//  Camera.cpp
//  VerizonTest
//
//  Created by James Folk on 6/21/16.
//  Copyright © 2016 NJLIGames Ltd. All rights reserved.
//

#include "Camera.h"
#include "Node.h"
#include "Shader.h"

namespace NJLIC {
    static inline glm::mat4x4 setFrom4x4Matrix(const float *m) {
        glm::mat4 _m;

        _m[0][0] = m[0];
        _m[1][0] = m[1];
        _m[2][0] = m[2];
        _m[3][0] = m[3];

        _m[0][1] = m[4];
        _m[1][1] = m[5];
        _m[2][1] = m[6];
        _m[3][1] = m[7];

        _m[0][2] = m[8];
        _m[1][2] = m[9];
        _m[2][2] = m[10];
        _m[3][2] = m[11];

        _m[0][3] = m[12];
        _m[1][3] = m[13];
        _m[2][3] = m[14];
        _m[3][3] = m[15];

        return _m;
    }

    glm::mat4x4 Camera::makeFrustum(float *matrixBuffer, float fov,
                                    float aspect, float nearDist, float farDist,
                                    bool leftHanded) {
        memset(matrixBuffer, 0, sizeof(float) * 16);
        //
        // General form of the Projection Matrix
        //
        // uh = Cot( fov/2 ) == 1/Tan(fov/2)
        // uw / uh = 1/aspect
        //
        //   uw         0       0       0
        //    0        uh       0       0
        //    0         0      f/(f-n)  1
        //    0         0    -fn/(f-n)  0
        //
        // Make result to be identity first

        //    0         1       2       3
        //    4         5       6       7
        //    8         9      10      11
        //   12        13      14      15

        // check for bad parameters to avoid divide by zero:
        // if found, assert and return an identity matrix.
        if (fov <= 0 || aspect == 0) {
            return glm::mat4x4(1.0);
        }

        float frustumDepth = farDist - nearDist;
        float oneOverDepth = 1.0f / frustumDepth;

        matrixBuffer[5] = 1.0f / tan(0.5f * glm::radians(fov));
        matrixBuffer[0] =
            (leftHanded ? 1.0f : -1.0f) * matrixBuffer[5] / aspect;
        matrixBuffer[10] = farDist * oneOverDepth;
        matrixBuffer[14] = (-farDist * nearDist) * oneOverDepth;
        matrixBuffer[11] = 1.0f;
        matrixBuffer[15] = 0;

        return setFrom4x4Matrix(matrixBuffer);
    }

    glm::mat4x4 Camera::makeLookAt(float *buffer, float eyeX, float eyeY,
                                   float eyeZ, float centerX, float centerY,
                                   float centerZ, float upX, float upY,
                                   float upZ) {
        assert(buffer);

        glm::vec3 ev(eyeX, eyeY, eyeZ);
        glm::vec3 cv(centerX, centerY, centerZ);
        glm::vec3 uv(upX, upY, upZ);
        //        glm::vec3 n((ev + -cv).normalized());
        glm::vec3 n(glm::normalize(ev + -cv));
        //        glm::vec3 u((uv.cross(n).normalized()));
        glm::vec3 u(glm::normalize(glm::cross(uv, n)));
        //        glm::vec3 v(n.cross(u));
        glm::vec3 v(glm::cross(n, u));

        buffer[0] = u.x;
        buffer[1] = v.x;
        buffer[2] = n.x;
        buffer[3] = 0.0f;
        buffer[4] = u.y;
        buffer[5] = v.y;
        buffer[6] = n.y;
        buffer[7] = 0.0f;
        buffer[8] = u.z;
        buffer[9] = v.z;
        buffer[10] = n.z;
        buffer[11] = 0.0f;
        //        buffer[12] = (-u).dot(ev);
        buffer[12] = glm::dot(-u, ev);

        //        buffer[13] = (-v).dot(ev);
        buffer[13] = glm::dot(-v, ev);

        //        buffer[14] = (-n).dot(ev);
        buffer[14] = glm::dot(-n, ev);

        buffer[15] = 1.0f;

        return setFrom4x4Matrix(buffer);
    }

    Camera::Camera()
        : m_MatrixBuffer(new float[16]),
          m_ProjectionMatrixBuffer(new GLfloat[16]), m_NodeOwner(NULL),
          m_Near(0.1f), m_Far(3000.0f), m_Fov(45.0f), m_AspectRatio(1.0f),
          mProjectionMatrix(new glm::mat4x4()), m_ModelViewDirty(true),
          m_ProjectionDirty(true) {
        *mProjectionMatrix =
            makeFrustum(m_ProjectionMatrixBuffer, getFov(), getAspectRatio(),
                        getZNear(), getZFar());
        m_ProjectionDirty = true;
    }

    Camera::~Camera() {

        delete mProjectionMatrix;
        mProjectionMatrix = NULL;

        delete[] m_ProjectionMatrixBuffer;
        m_ProjectionMatrixBuffer = NULL;

        delete[] m_MatrixBuffer;
        m_MatrixBuffer = NULL;
    }

    void Camera::setZNear(const float val) {
        bool changed = (val != getZNear());

        m_Near = val;

        if (changed) {
            *mProjectionMatrix =
                makeFrustum(m_ProjectionMatrixBuffer, getFov(),
                            getAspectRatio(), getZNear(), getZFar());
            m_ProjectionDirty = true;
        }
    }

    float Camera::getZNear() const { return m_Near; }

    void Camera::setZFar(const float val) {
        bool changed = (val != getZFar());

        m_Far = val;

        if (changed) {
            *mProjectionMatrix =
                makeFrustum(m_ProjectionMatrixBuffer, getFov(),
                            getAspectRatio(), getZNear(), getZFar());
            m_ProjectionDirty = true;
        }
    }

    float Camera::getZFar() const { return m_Far; }

    void Camera::setFov(const float val) {
        bool changed = (val != getFov());

        m_Fov = val;

        if (changed) {
            *mProjectionMatrix =
                makeFrustum(m_ProjectionMatrixBuffer, getFov(),
                            getAspectRatio(), getZNear(), getZFar());
            m_ProjectionDirty = true;
        }
    }

    float Camera::getFov() const { return m_Fov; }

    void Camera::setAspectRatio(const float val) {
        bool changed = (val != getAspectRatio());

        m_AspectRatio = val;

        if (changed) {
            *mProjectionMatrix =
                makeFrustum(m_ProjectionMatrixBuffer, getFov(),
                            getAspectRatio(), getZNear(), getZFar());
            m_ProjectionDirty = true;
        }
    }

    float Camera::getAspectRatio() const { return m_AspectRatio; }

    glm::mat4x4 Camera::getModelView() const {
        if (getNodeOwner())
            return getNodeOwner()->getWorldTransform();
        return glm::mat4x4(1.0);
    }

    glm::mat4x4 Camera::getProjectionMatrix() const {
        return *mProjectionMatrix;
    }

    Node *const Camera::getNodeOwner() const { return m_NodeOwner; }

    void Camera::setNodeOwner(Node *const node) { m_NodeOwner = node; }

    void Camera::lookAt(const glm::vec3 &target, const glm::vec3 &up) {
        glm::mat4x4 _btTransform(makeLookAt(
            m_MatrixBuffer, getNodeOwner()->getOrigin().x,
            getNodeOwner()->getOrigin().y, getNodeOwner()->getOrigin().z,
            target.x, target.y, target.z, up.x, up.y, up.z));
        *mProjectionMatrix = _btTransform;
    }

    void Camera::render(Shader *const shader, bool shouldRedraw) {
        if (m_ModelViewDirty || shouldRedraw) {
            (shader->setUniformValue("modelView", getModelView()));
            m_ModelViewDirty = false;
        }

        if (m_ProjectionDirty || shouldRedraw) {
            (shader->setUniformValue("projection", m_ProjectionMatrixBuffer));
            m_ProjectionDirty = false;
        }
    }
} // namespace NJLIC
