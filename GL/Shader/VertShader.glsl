#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec2 Coords;

out vec2 TexCoord;

uniform mat4x4 model;
uniform mat4x4 view;
uniform mat4x4 projection;

void main(){
    gl_Position= projection * view * model * vec4(position.xyz,1.0);
    TexCoord = Coords;
}
