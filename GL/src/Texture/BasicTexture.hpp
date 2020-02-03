//
//  Texture.hpp
//  GL
//
//  Created by Chen.Zr on 2020/2/2.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <SOIL/SOIL.h>
#include <string>
#include <GL/glew.h>
#include <iostream>
#include "NonCopyable.hpp"

struct Image {
    unsigned char *data;
    int width;
    int height;
};

class BasicTexture: public NonCopyable{
    public:
        
        BasicTexture(const std::string &imageName);
        
        void loadFromFile(const std::string &imageName);
        void loadFromImage(Image image);
        
        void bindTexture() const;
        
        ~BasicTexture();

    private:
        GLuint textureID;
};

#endif /* Texture_hpp */
