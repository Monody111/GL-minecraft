#version 330 core

layout(location=0) in vec3 position;

out vec3 TexCoord;

uniform mat4x4 view;
uniform mat4x4 projection;

void main(){
    gl_Position= projection * view * vec4(position, 1.0);
    TexCoord = position;
}

