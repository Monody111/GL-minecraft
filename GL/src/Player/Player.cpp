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
    camera = new Camera(&this -> position, setting);
    controller = new Controller();
}

void Player::movement(GLfloat deltaTime) {
    if (controller -> keys[GLFW_KEY_W]) {
        camera->ProcessMovement(FORWARD, deltaTime);
    }
    if (controller -> keys[GLFW_KEY_S]) {
        camera->ProcessMovement(BACKWARD, deltaTime);
    }
    if (controller -> keys[GLFW_KEY_A]) {
        camera->ProcessMovement(LEFT, deltaTime);
    }
    if (controller -> keys[GLFW_KEY_D]) {
        camera->ProcessMovement(RIGHT, deltaTime);
    };
}

void Player::view(){
    camera -> ProcessMouseMovement(controller -> xoffset, controller -> yoffset);
    controller -> xoffset = 0.0f;
    controller -> yoffset = 0.0f;
}

void Player::verticality(GLfloat deltaTime) {
    if (controller -> keys[GLFW_KEY_SPACE]) {
        camera->ProcessVerticality(ABOVE, deltaTime);
    }
    if (controller -> keys[GLFW_KEY_LEFT_SHIFT]) {
        camera->ProcessVerticality(BOTTOM, deltaTime);
    };
}





