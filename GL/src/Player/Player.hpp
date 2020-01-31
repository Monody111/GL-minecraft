//
//  Player.hpp
//  GL
//
//  Created by Chen.Zr on 2020/1/27.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <glm/glm.hpp>
#include "Controller.hpp"
#include "GameSetting.hpp"
#include "Camera.hpp"

class Player {

public:
    glm::vec3 position;
    
    Controller *controller = nullptr;
    Camera *camera = nullptr;
    
    Player(GameSetting *setting);
    
    void movement(GLfloat deltaTime);
    void view();
};

#endif /* Player_hpp */
