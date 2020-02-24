//#version 100
                                                                                       
attribute vec4 a_Position;
attribute vec4 a_Color;
attribute vec4 a_Texture;
                                                                                       
varying vec2 textureCoordinate;
varying vec4 frag_Color;
                                                                                       
void main(void) {
    frag_Color = a_Color;
    gl_Position = a_Position;
    textureCoordinate = a_Texture.xy;
}
