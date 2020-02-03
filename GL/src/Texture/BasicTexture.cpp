//
//  Texture.cpp
//  GL
//
//  Created by Chen.Zr on 2020/2/2.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "BasicTexture.hpp"

void BasicTexture::loadFromFile(const std::string &imageName) {
    Image image;
    image.data = SOIL_load_image(("Res/Textures/" + imageName).c_str(),
                                 &image.width, &image.height,0,
                                 SOIL_LOAD_RGBA);
    
    if (image.data == 0) {
        throw std::runtime_error("Unable to load BasicTexture: " + imageName);
    }
    loadFromImage(image);
}

BasicTexture::BasicTexture(const std::string &imageName) {
    loadFromFile(imageName);
}

void BasicTexture::bindTexture() const { 
    glBindTexture(GL_TEXTURE_2D, textureID);
}


void BasicTexture::loadFromImage(Image image) {
    glGenTextures(1, &textureID);
//    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 image.width, image.height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image.data);
    SOIL_free_image_data(image.data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);
    glBindTexture(GL_TEXTURE_2D, 0);
}

BasicTexture::~BasicTexture() {
    glDeleteTextures(1, &textureID);
}



