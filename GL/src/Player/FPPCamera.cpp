//
//  Camera.cpp
//  learn
//
//  Created by Chen.Zr on 2019/10/11.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//
#include "FPPCamera.hpp"

FPPCamera::FPPCamera(glm::vec3 cameraPosition, glm::vec3 worldUp, glm::vec3 front,
               GLfloat yaw, GLfloat pitch, GameSetting *setting){
    setCamera(cameraPosition, worldUp, front, yaw, pitch);
    this -> setting = setting;
}

FPPCamera::FPPCamera(glm::vec3 cameraPosition, GameSetting *setting){
    setCamera(cameraPosition,
              glm::vec3(0.0,1.0,0.0),
              glm::vec3(0.0,0.0,-1.0),
              -90.0f, 0.0f);
    
    this -> setting = setting;
}

void FPPCamera::setCamera(glm::vec3 cameraPosition, glm::vec3 worldUp,                             glm::vec3 front, GLfloat yaw, GLfloat pitch) {
    this -> position = cameraPosition;
    this -> WorldUp = worldUp;
    
    this -> Front = front;
    
    this->Yaw = yaw;
    this->Pitch = pitch;
    
    this->updateCameraVectors();
}

glm::mat4 FPPCamera::getViewMatrix() const{ 
    return glm::lookAt(this->position, this->position + this->Front, this->Up);
}

void FPPCamera::ProcessMovement(Camera_Movement direction, GLfloat velocity) {

    if (direction == FORWARD) {
        this->position += this->forward * velocity;
    }
    if (direction == BACKWARD) {
        this->position -= this->forward * velocity;
    }
    if (direction == RIGHT) {
        this->position += this->Right * velocity;
    }
    if (direction == LEFT) {
        this->position -= this->Right * velocity;
    }
}

void FPPCamera::ProcessMouseMovement(GLfloat offsetX, GLfloat offsetY) {
    offsetX *= setting -> sensitivity;
    offsetY *= setting -> sensitivity;
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

//void Camera::ProcessMouseScroll(GLfloat offsetY) { 
//    if(this->fov >= 1.0 && this->fov <= 45.0){
//        this->fov -= offsetY * 0.1;
//    }else if (this->fov <= 1.0){
//        this->fov = 1.0;
//    }else if (this->fov >= 45.0){
//        this->fov = 45.0;
//    }
//}

void FPPCamera::updateCameraVectors() {
    Front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    Front.y = sin(glm::radians(this->Pitch));
    Front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    this->Front = glm::normalize(Front);
    this->forward = glm::normalize(glm::vec3(Front.x, 0.0, Front.z));
    this->Right = glm::normalize(glm::cross(this->Front,this->WorldUp));
    this->Up = glm::normalize(glm::cross(this->Right, this->Front));

}

glm::mat4 FPPCamera::getPerspectiveMatrix() const {
    return glm::perspective(setting -> fov, (float)setting->width/setting->height, 0.01f, 1000.0f);
}

void FPPCamera::ProcessVerticality(Camera_Movement direction, GLfloat velocity){
    if (direction == ABOVE) {
        this->position += this->WorldUp * velocity;
    }
    if (direction == BOTTOM) {
        this->position -= this->WorldUp * velocity;
    }
}





