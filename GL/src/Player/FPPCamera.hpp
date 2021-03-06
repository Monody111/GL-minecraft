//
//  Camera.hpp
//  learn
//
//  Created by Chen.Zr on 2019/10/11.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "GameSetting.hpp"

// enum be used in movement
enum Camera_Movement{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    ABOVE,
    BOTTOM
};

class FPPCamera{
public:
    //camera position
    glm::vec3 position;
    //camera front
    glm::vec3 Front;
    //move forward
    glm::vec3 forward;
    //camera up
    glm::vec3 Up;
    //camera right
    glm::vec3 Right;
    //world up
    glm::vec3 WorldUp;
    
    GameSetting *setting;
    
    GLfloat Pitch = 0.0f;
    GLfloat Yaw = -90.0f;

    
    FPPCamera(glm::vec3 cameraPosition,
           glm::vec3 WorldUp, glm::vec3 front,
           GLfloat yaw, GLfloat pitch, GameSetting *setting);
    
    FPPCamera(glm::vec3 cameraPosition, GameSetting *setting);
    
    void setCamera(glm::vec3 cameraPosition, glm::vec3 worldUp,
                   glm::vec3 front, GLfloat yaw, GLfloat pitch);
    
    glm::mat4 getViewMatrix() const;
    glm::mat4 getPerspectiveMatrix() const;
    
    void ProcessMovement(Camera_Movement direction, GLfloat velocity);
    void ProcessVerticality(Camera_Movement direction, GLfloat velocity);
    void ProcessMouseMovement(GLfloat offsetX, GLfloat offsetY);
//    void ProcessMouseScroll(GLfloat offsetY);
    
private:
    void updateCameraVectors();
};
#endif /* Camera_hpp */
