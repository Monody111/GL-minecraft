//
//  Player.cpp
//  GL
//
//  Created by Chen.Zr on 2020/1/27.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "Player.hpp"

Player::Player(GameSetting *setting, glm::vec3 spawnPosition) {
    this -> position = spawnPosition;
    this -> camera = new FPPCamera(this -> position, setting);
    this -> controller = new Controller();
    this -> setting = setting;
}

void Player::movement(GLfloat deltaTime) {
    GLfloat velocity = setting -> speed * deltaTime;
    
    if (controller -> keys[GLFW_KEY_W]) {
        camera->ProcessMovement(FORWARD, velocity);
    }
    if (controller -> keys[GLFW_KEY_S]) {
        camera->ProcessMovement(BACKWARD, velocity);
    }
    if (controller -> keys[GLFW_KEY_A]) {
        camera->ProcessMovement(LEFT, velocity);
    }
    if (controller -> keys[GLFW_KEY_D]) {
        camera->ProcessMovement(RIGHT, velocity);
    };
    setLoation();
}

void Player::view(){
    camera -> ProcessMouseMovement(controller -> xoffset, controller -> yoffset);
    controller -> xoffset = 0.0f;
    controller -> yoffset = 0.0f;
}

void Player::verticality(GLfloat deltaTime) {
    GLfloat velocity = setting -> speed * deltaTime;
    
    if (controller -> keys[GLFW_KEY_SPACE]) {
        camera->ProcessVerticality(ABOVE, velocity);
    }
    if (controller -> keys[GLFW_KEY_LEFT_SHIFT]) {
        camera->ProcessVerticality(BOTTOM, velocity);
    };
    setLoation();
}






