uniform sampler2D videoFrame;

varying highp vec2 textureCoordinate;
varying lowp vec4 frag_Color;

void main(void) {
    gl_FragColor = texture2D(videoFrame, textureCoordinate) * frag_Color;
}

