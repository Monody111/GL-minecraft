//
//  ShaderLoader.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/5.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#ifndef ShaderLoader_hpp
#define ShaderLoader_hpp

#include <GL/glew.h>
#include <string>
#include <iostream>
#include "FileUtil.hpp"

GLuint complieShader(const GLchar *shaderSouce, GLenum type);
GLuint linkShader(GLuint vertShader, GLuint fragShader);
GLuint loadShader(const std::string &vertShaderPath, const std::string &fragShaderPath);

#endif /* ShaderLoader_hpp */
