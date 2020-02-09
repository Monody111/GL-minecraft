//
//  InstancingRenderer.cpp
//  GL
//
//  Created by Chen.Zr on 2020/1/31.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "InstancingRenderer.hpp"

void InstancingRenderer::render(BasicTexture *t) {
    shader->Use();
    glm::mat4 viewMat4 = camera -> getViewMatrix();
//    glm::mat4 modelMat4 = glm::translate(glm::mat4(1.0), component -> position);
    glm::mat4 projectionMat4 = camera -> getPerspectiveMatrix();
    
//    GLint modelLoc = glGetUniformLocation(shader->program, "model");
    GLint viewlLoc = glGetUniformLocation(shader->program, "view");
    GLint projectionLoc = glGetUniformLocation(shader->program, "projection");
    
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMat4));
    glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(viewMat4));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMat4));
    
    t -> bindTexture();
    

    mesh->bindVAO();
    glDrawArraysInstanced(GL_TRIANGLES, 0, 36, 256);
    glBindVertexArray(0);
}
