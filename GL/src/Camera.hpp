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
#include "GameSetting.hpp"

// enum be used in movement
enum Camera_Movement{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const GLfloat YAW = -90.0;

const GLfloat PITCH = 0.0;
const GLfloat ZOOM = 45.0;
const GLfloat SPEED = 3.0;
const GLfloat SENSITIVITY = 0.05;

class Camera{
public:
    //camera position
    glm::vec3 Position;
    //camera front
    glm::vec3 Front;
    //camera up
    glm::vec3 Up;
    //camera right
    glm::vec3 Right;
    //world up
    glm::vec3 WorldUp;
    
    GameSetting *setting;
    
    GLfloat Pitch = 0.0f;
    GLfloat Yaw = -90.0f;
    
    GLfloat MovementSpeed;
    GLfloat Sensitivity;
    GLfloat fov;
    
    Camera(glm::vec3 cameraPosition,
           glm::vec3 WorldUp,
           GLfloat yaw, GLfloat pitch, GameSetting *setting);
    
    Camera(glm::vec3 cameraPosition, GameSetting *setting);
    
    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch);
    
    void setCamera(glm::vec3 position, glm::vec3 worldUp, GLfloat yaw, GLfloat pitch,
    GLfloat speed, GLfloat sensitivity, GLfloat fov);
    
    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetPerspectiveMatrix() const;
    void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);
    void ProcessMouseMovement(GLfloat offsetX, GLfloat offsetY);
    void ProcessMouseScroll(GLfloat offsetY);
    
private:
    void updateCameraVectors();
};
#endif /* Camera_hpp */
