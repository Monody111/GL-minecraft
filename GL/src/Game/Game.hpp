//
//  Game.hpp
//  testSFML
//
//  Created by Chen.Zr on 2020/1/25.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.hpp"
#include "DefaultRenderer.hpp"
#include "GameSetting.hpp"
#include "CubeComponent.hpp"
#include "Player.hpp"
#include "InstancingRenderer.hpp"
#include "Section.hpp"
#include "BasicTexture.hpp"
class Game {
    
public:
    GameSetting *setting = nullptr;
    GLFWwindow *window = nullptr;
    Renderer *renderer = nullptr;
//    Controller *c;
    GLfloat lastTime = 0.0;
    GLfloat currentTime = 0.0;
    Player *player = nullptr;
    
    BasicTexture *texture = nullptr;
    
    Game(GameSetting *setting);
    
    inline static void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods){
        Controller *c = static_cast<Controller*>(glfwGetWindowUserPointer(window));
        c -> key_callback(window, key, scancode, action, mods);
    }
    
    inline static void cursorpos_callback(GLFWwindow *window, double xpos, double ypos){
        Controller *c = static_cast<Controller*>(glfwGetWindowUserPointer(window));
        c -> mouse_callback(window, xpos, ypos);
    }

    void loadWindow();
    void runLoop();
    void loadRenderer();
};

#endif /* Game_hpp */
