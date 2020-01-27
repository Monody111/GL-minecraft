//
//  Controller.hpp
//  GL
//
//  Created by Chen.Zr on 2020/1/27.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GameSetting.hpp"

class Controller {
public:
    
    bool keys[1024];
    bool firstMouse = true;
    GLfloat deltaTime = 0.0f;
    GLfloat lastTime = 0.0f;
    GLfloat lastX, lastY;
    
    Controller() = default;
    
    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    
    void mouse_callback(GLFWwindow *window, double xpos, double ypos);

};

#endif /* Controller_hpp */
