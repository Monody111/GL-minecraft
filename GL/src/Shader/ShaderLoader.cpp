//
//  ShaderLoader.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/5.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#include "ShaderLoader.hpp"

GLuint complieShader(const GLchar *shaderSource, GLenum type){
    GLuint shader = glCreateShader(type);
    GLint success;
    GLchar infoLog[512];
    
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
    
    glGetShaderiv(shader,GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout <<"ERROR::SHADER::"<<type<<"::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return shader;
}

GLuint linkShader(GLuint vertShader, GLuint fragShader){
    GLuint program = glCreateProgram();
    GLint success;
    GLchar infoLog[512];
    
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);
    
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::LINK::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return program;
}

GLuint loadShader(const std::string &vertShaderPath, const std::string &fragShaderPath){
    std::string vertShaderSource = getFileContents(vertShaderPath);
    std::string fragShaderSource = getFileContents(fragShaderPath);
    
    GLuint vert = complieShader(vertShaderSource.c_str(), GL_VERTEX_SHADER);
    GLuint frag = complieShader(fragShaderSource.c_str(), GL_FRAGMENT_SHADER);
    GLuint program = linkShader(vert, frag);
    
    glDeleteShader(vert);
    glDeleteShader(frag);
    
    return program;
}
