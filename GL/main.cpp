//
//  main.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/10/20.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//
#include <iostream>
#include "GameSetting.hpp"
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    GameSetting *setting = new GameSetting();
    Game *game = new Game(setting);
    game -> loadRenderer();
    game -> runLoop();
}
