//
//  Controller.cpp
//  GL
//
//  Created by Chen.Zr on 2020/1/27.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "Controller.hpp"

void Controller::key_callback(GLFWwindow *window,int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key >= 0 && key <= 1024) {
        if (action == GLFW_PRESS) {
            keys[key] = true;
        }else if (action == GLFW_RELEASE){
            keys[key] = false;
        }
    }
}

void Controller::mouse_callback(GLFWwindow *window, double xpos, double ypos){
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    xoffset = lastX - xpos;
    yoffset = ypos - lastY;

    lastX = xpos;
    lastY = ypos;
    
    std::cout << "xoffset = " << xoffset <<", " << "yoffset = " << yoffset <<std::endl;
//    camera->ProcessMouseMovement(xoffset, yoffset);
}

