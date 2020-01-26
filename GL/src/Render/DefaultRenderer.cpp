//
//  DefaultRenderer.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "./DefaultRenderer.hpp"

void DefaultRenderer::render() {
    glm::mat4 modelMat4(1.0);
    glm::mat4 viewMat4(1.0);
    glm::mat4 projectionMat4(1.0);
    
    viewMat4 = camera->GetViewMatrix();
    modelMat4 = glm::translate(modelMat4, glm::vec3(0.0));
    projectionMat4 = glm::perspective(camera->Zoom, (float)800/600, 0.1f, 1000.0f);
    
    GLint modelLoc = glGetUniformLocation(shader->program, "model");
    GLint viewlLoc = glGetUniformLocation(shader->program, "view");
    GLint projectionLoc = glGetUniformLocation(shader->program, "projection");
    
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMat4));
    glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(viewMat4));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMat4));
    
    shader->Use();
    model->bindVAO();
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void DefaultRenderer::bindModel(Model *model) {
    if(model){
        this->model = model;
    }
}

void DefaultRenderer::bindCamera(Camera *camera) {
    this->camera = camera;
}

void DefaultRenderer::bindShader(Shader *shader) {
    this->shader = shader;
}

