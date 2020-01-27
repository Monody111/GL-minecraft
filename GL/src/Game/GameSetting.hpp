//
//  GameSetting.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/26.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef GameSetting_hpp
#define GameSetting_hpp

#include <GL/glew.h>

struct GameSetting{
    int width = 800;
    int height = 600;
    bool fullScreen = false;
    GLfloat fov = 90.0f;
    GLfloat speed = 3.0;
    GLfloat sensitivity = 0.05;
};

#endif /* GameSetting_hpp */
