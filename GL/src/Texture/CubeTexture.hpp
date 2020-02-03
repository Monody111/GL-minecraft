//
//  CubeTexture.hpp
//  GL
//
//  Created by Chen.Zr on 2020/2/3.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef CubeTexture_hpp
#define CubeTexture_hpp

#include <GL/glew.h>
#include <string>
#include <array>

#include "BasicTexture.hpp"
#include "NonCopyable.hpp"

class CubeTexture: public NonCopyable{
    
public:
    CubeTexture(const std::array<std::string, 6> &images);
    
//    由于立方体贴图有6个面，OpenGL就提供了6个不同的纹理目标，来应对立方体贴图的各个面。
//
//    纹理目标（Texture target）          方位
//    GL_TEXTURE_CUBE_MAP_POSITIVE_X    右
//    GL_TEXTURE_CUBE_MAP_NEGATIVE_X    左
//    GL_TEXTURE_CUBE_MAP_POSITIVE_Y    上
//    GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    下
//    GL_TEXTURE_CUBE_MAP_POSITIVE_Z    后
//    GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    前

    void loadFromFile(const std::array<std::string, 6> &images);

    void bindTexture() const;

private:
    GLuint textureID;
};

#endif /* CubeTexture_hpp */
