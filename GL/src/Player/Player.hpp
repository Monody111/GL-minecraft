//
//  Player.hpp
//  GL
//
//  Created by Chen.Zr on 2020/1/27.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Controller.hpp"
#include "GameSetting.hpp"

class Player {

public:
    Controller *controller;
//    GameSetting *setting;
    
//    Player(GameSetting *s);
    
    void movement();
};

#endif /* Player_hpp */
