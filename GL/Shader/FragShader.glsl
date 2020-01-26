#version 330 core

out vec4 color;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main(){
    color = vec4(1.0, 1.0, 1.0, 1.0);
//    color = texture(ourTexture, TexCoord) * vec4(1.0, 1.0, 1.0, 1.0);
}
