//
//  SkyboxRenderer.cpp
//  GL
//
//  Created by Chen.Zr on 2020/2/3.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "SkyboxRenderer.hpp"



SkyboxRenderer::SkyboxRenderer(const std::string &vertShaderName,
                               const std::string &fragShaderName):
                               Renderer(vertShaderName, fragShaderName){
                                   loadModel();
                                   loadTexture();
                               }

void SkyboxRenderer::renderSky() {
    glDepthMask(GL_FALSE);
    shader -> Use();
    glm::mat4 viewMat4 = camera -> getViewMatrix();
    viewMat4[3][0] = 0;
    viewMat4[3][1] = 0;
    viewMat4[3][2] = 0;
//    glm::mat4 viewMat4 = glm::mat4(glm::mat3(camera -> GetViewMatrix()));
    glm::mat4 projectionMat4 = camera -> getPerspectiveMatrix();
    
    GLint viewlLoc = glGetUniformLocation(shader->program, "view");
    GLint projectionLoc = glGetUniformLocation(shader->program, "projection");
    
    glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(viewMat4));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projectionMat4));
    
    model -> bindVAO();
    
    glActiveTexture(GL_TEXTURE0);
    glUniform1i(glGetUniformLocation(shader -> program, "skybox"), 0);
    cubetexture -> bindTexture();
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthMask(GL_TRUE);
}

void SkyboxRenderer::loadModel() { 
    model = new Model();
    model -> createVAO();
    model -> addVBO(3, vertextPosition);
}

void SkyboxRenderer::loadTexture() {
    cubetexture = new CubeTexture({
        "right.jpg",
        "left.jpg",
        "top.jpg",
        "bottom.jpg",
        "back.jpg",
        "front.jpg"
    });
}

void SkyboxRenderer::render(BasicTexture *t) {
}



