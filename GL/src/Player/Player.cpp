//
//  Player.cpp
//  GL
//
//  Created by Chen.Zr on 2020/1/27.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "Player.hpp"

Player::Player(GameSetting *setting) { 
    camera = new Camera(glm::vec3(0.0, 0.0, 3.0), setting);
    controller = new Controller();
}

void Player::movement(GLfloat deltaTime) {
    if (controller -> keys[GLFW_KEY_W]) {
        camera->ProcessKeyboard(FORWARD, deltaTime);
    }
    if (controller -> keys[GLFW_KEY_S]) {
        camera->ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (controller -> keys[GLFW_KEY_A]) {
        camera->ProcessKeyboard(LEFT, deltaTime);
    }
    if (controller -> keys[GLFW_KEY_D]) {
        camera->ProcessKeyboard(RIGHT, deltaTime);
    };
    position = camera -> Position;
}

void Player::view(){
    camera -> ProcessMouseMovement(controller -> xoffset, controller -> yoffset);
    controller -> xoffset = 0.0f;
    controller -> yoffset = 0.0f;
}


