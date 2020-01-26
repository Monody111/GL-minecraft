//
//  Shader.cpp
//  learn
//
//  Created by Chen.Zr on 2019/10/6.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#include "Shader.hpp"

Shader::Shader(const std::string &vertShaderPath, const std::string &fragShaderPath)
{
    load(vertShaderPath, fragShaderPath);
}

void Shader::Use() {
    glUseProgram(this->program);
}

void Shader::load(const std::string &vertShaderPath, const std::string &fragShaderPath) { 
    this->program = loadShader(vertShaderPath, fragShaderPath);
}

