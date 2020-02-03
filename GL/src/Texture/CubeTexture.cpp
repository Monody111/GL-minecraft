//
//  CubeTexture.cpp
//  GL
//
//  Created by Chen.Zr on 2020/2/3.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "CubeTexture.hpp"


void CubeTexture::loadFromFile(const std::array<std::string, 6> &images) { 
    glGenTextures(1, &textureID);
//    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    for (int i = 0; i < 6; i++)
    {
        auto &imageName = images[i];
        Image image;
        image.data = SOIL_load_image(("Res/Textures/skybox/" + imageName).c_str(),
                                     &image.width, &image.height, 0,
                                     SOIL_LOAD_RGBA);
        if (image.data == 0){
            throw std::runtime_error("Unable to load CubeTexture Part: " + imageName);
        }

        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0,
                     GL_RGBA, image.width, image.height, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, image.data);
        SOIL_free_image_data(image.data);
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void CubeTexture::bindTexture() const {
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
}

CubeTexture::CubeTexture(const std::array<std::string, 6> &images) { 
    loadFromFile(images);
}


