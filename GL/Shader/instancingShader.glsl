#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec2 Coords;
layout(location=2) in vec3 offset;

out vec2 TexCoord;

//uniform mat4x4 model;
uniform mat4x4 view;
uniform mat4x4 projection;

void main(){

    gl_Position = projection * view * vec4(position + offset, 1.0f);
    TexCoord = Coords;
}

