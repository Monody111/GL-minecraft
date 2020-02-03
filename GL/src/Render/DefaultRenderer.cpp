//
//  DefaultRenderer.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "DefaultRenderer.hpp"

void DefaultRenderer::render(BasicTexture *t) {
    
    glm::mat4 viewMat4 = camera -> GetViewMatrix();
//    glm::mat4 modelMat4 = glm::translate(glm::mat4(1.0), component -> position);
    glm::mat4 projectionMat4 = camera -> GetPerspectiveMatrix();
    
//    GLint modelLoc = glGetUniformLocation(shader->program, "model");
    GLint viewlLoc = glGetUniformLocation(shader->program, "view");
    GLint projectionLoc = glGetUniformLocation(shader->program, "projection");
    
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMat4));
    glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(viewMat4));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMat4));
    
    shader->Use();
    model->bindVAO();
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void DefaultRenderer::bindModel(Model *model) {
    if(model){
        this->model = model;
    }else{
        throw std::runtime_error("Unable to bind model to render: ");
    }
}
void DefaultRenderer::bindCamera(Camera *camera) {
    if(camera){
        this->camera = camera;
    }else{
        throw std::runtime_error("Unable to bind camera to render: ");
    }
}

//void DefaultRenderer::loadShader(Shader *shader) {
//    if(shader){
//        this->shader = shader;
//    }else{
//        throw std::runtime_error("Unable to bind shader to render: ");
//    }
//}


