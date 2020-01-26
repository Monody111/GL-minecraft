//
//  Shader.hpp
//  learn
//
//  Created by Chen.Zr on 2019/10/6.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <string>
#include <GL/glew.h>
#include "ShaderLoader.hpp"

class Shader {
public:
    GLuint program;
    Shader() = default;
    Shader(const std::string &vertShaderPath, const std::string &fragShaderPath);
    void load(const std::string &vertShaderPath, const std::string &fragShaderPath);
    void Use();
};

#endif /* Shader_hpp */
