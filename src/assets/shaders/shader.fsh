//#version 100
                                                                                       
uniform sampler2D videoFrame;
                                                                                       
varying vec2 textureCoordinate;
varying vec4 frag_Color;
                                                                                       
void main(void) {
    gl_FragColor = texture2D(videoFrame, textureCoordinate) * frag_Color;
}
