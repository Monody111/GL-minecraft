//
//  main.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/10/20.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
//#include "Shader/ShaderLoader.hpp"
//#include "Camera.hpp"
//#include "Texture.hpp"
//#include "Model.hpp"
#include "DefaultRenderer.hpp"
#include "CubeComponent.hpp"
//#include "CubeRenderer.hpp"
#include "GameSetting.hpp"
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    GameSetting *setting = new GameSetting();
    Game *game = new Game(setting);
    game -> loadRenderer();
    game -> runLoop();
}
