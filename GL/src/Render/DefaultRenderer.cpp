//
//  DefaultRenderer.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "DefaultRenderer.hpp"

void DefaultRenderer::render() {
    glm::mat4 modelMat4(1.0);
    glm::mat4 viewMat4(1.0);
    glm::mat4 projectionMat4(1.0);
    
    viewMat4 = camera->GetViewMatrix();
    modelMat4 = glm::translate(glm::mat4(1.0), component -> position);
    projectionMat4 = glm::perspective(camera->fov, (float)800/600, 0.1f, 1000.0f);
    
    GLint modelLoc = glGetUniformLocation(shader->program, "model");
    GLint viewlLoc = glGetUniformLocation(shader->program, "view");
    GLint projectionLoc = glGetUniformLocation(shader->program, "projection");
    
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMat4));
    glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(viewMat4));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMat4));
    
    shader->Use();
    mesh->bindVAO();
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void DefaultRenderer::bindMesh(BaseComponent *mesh) {
    if(mesh){
        this->mesh = mesh -> model;
        this->component = mesh;
    }else{
        std::cout << "invaild pointer mesh" << std::endl;
    }
}
void DefaultRenderer::bindCamera(Camera *camera) {
    if(camera){
        this->camera = camera;
    }else{
        std::cout << "invaild pointer camera" << std::endl;
    }
}

void DefaultRenderer::bindShader(Shader *shader) {
    if(shader){
        this->shader = shader;
    }else{
        std::cout << "invaild pointer shader" << std::endl;
    }
}


