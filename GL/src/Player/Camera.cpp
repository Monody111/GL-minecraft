//
//  Camera.cpp
//  learn
//
//  Created by Chen.Zr on 2019/10/11.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//
#include <iostream>

#include "Camera.hpp"

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 worldUp,
               GLfloat yaw, GLfloat pitch, GameSetting *setting){
    setCamera(cameraPosition, worldUp, yaw, pitch, setting -> speed, setting -> sensitivity, setting -> fov);
    this -> setting = setting;
}

Camera::Camera(glm::vec3 cameraPosition, GameSetting *setting){
    setCamera(cameraPosition,
              glm::vec3(0.0,1.0,0.0),
              -90.0f, 0.0f,
              setting -> speed,
              setting -> sensitivity,
              setting -> fov);
    
    this -> setting = setting;
}

void Camera::setCamera(glm::vec3 position, glm::vec3 worldUp, GLfloat yaw, GLfloat pitch,
                       GLfloat speed, GLfloat sensitivity, GLfloat fov) {
    this -> Position = position;
    this -> WorldUp = worldUp;
    
    this->Yaw = yaw;
    this->Pitch = pitch;
    this->MovementSpeed = speed;
    this->Sensitivity = sensitivity;
    this->fov = fov;
    
    this->updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const{ 
    return glm::lookAt(this->Position, this->Position + this->Front, this->WorldUp);
}

void Camera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime) {
    GLfloat velocity = this->MovementSpeed * deltaTime;
    if (direction == FORWARD) {
        this->Position += this->Front * velocity;
    }
    if (direction == BACKWARD) {
        this->Position -= this->Front * velocity;
    }
    if (direction == RIGHT) {
        this->Position -= this->Right * velocity;
    }
    if (direction == LEFT) {
        this->Position += this->Right * velocity;
    }
    Position.y = 0.0f;
}

void Camera::ProcessMouseMovement(GLfloat offsetX, GLfloat offsetY) {
    offsetX *= this->Sensitivity;
    offsetY *= this->Sensitivity;
    Yaw += offsetX;
    Pitch += offsetY;
    if (this->Pitch > 89.0) {
        this->Pitch = 89.0;
    }
    if (this->Pitch < -89.0){
        this->Pitch = -89.0;
    }
    this->updateCameraVectors();
}

void Camera::ProcessMouseScroll(GLfloat offsetY) { 
    if(this->fov >= 1.0 && this->fov <= 45.0){
        this->fov -= offsetY * 0.1;
    }else if (this->fov <= 1.0){
        this->fov = 1.0;
    }else if (this->fov >= 45.0){
        this->fov = 45.0;
    }
}

void Camera::updateCameraVectors() { 
    glm::vec3 front(0.0,0.0,-1.0);
    front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    front.y = sin(glm::radians(this->Pitch));
    front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    this->Front = glm::normalize(front);
    this->Right = glm::normalize(glm::cross(this->Front,this->WorldUp));
    this->Up = glm::normalize(glm::cross(this->Right, this->Front));
}

glm::mat4 Camera::GetPerspectiveMatrix() const {
    return glm::perspective(setting->fov, (float)setting->width/setting->height, 0.01f, 1000.0f);
}




