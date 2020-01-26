//
//  CubeRenderer.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/5.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CubeRenderer.hpp"


CubeRenderer::CubeRenderer() {
//    texture.loadFromFilePath("../Res/Textures/Test.png");
    object.addData({
        1,1,1,
        1,1,0,
        1,0,1,
        1,0,0,
        0,1,1,
        0,1,0,
        0,0,1,
        0,0,0
    },{
        1, 1,
        0, 1,
        0, 0,
        1, 1
    });
//    }, {
//        0, 4, 2, //f
//        6, 2, 4,
//        4, 0, 5, //u
//        0, 1, 5,
//        2, 3, 0, //r
//        1, 0, 3,
//        4, 5, 6, //l
//        7, 6, 5,
//        5, 1, 7, //d
//        3, 7, 1,
//        2, 3, 6, //b
//        7, 6, 3,
//    });
    shader = Shader("./Shader/VertShader.glsl", "./Shader/FragShader.glsl");
}

//void CubeRenderer::add(const glm::vec3 &position) {
//    <#code#>;
//}

void CubeRenderer::render(const Camera &camera) {
    
    glm::mat4 model(1.0);
    glm::mat4 view(1.0);
    glm::mat4 projection(1.0);
    
    view = camera.GetViewMatrix();
    model = glm::translate(model, glm::vec3(-0.5));
    projection = glm::perspective(camera.Zoom, (float)800/600, 0.1f, 1000.0f);
    {
        //        lightshader.Use();
        //
        //        GLint modelLoc = glGetUniformLocation(lightshader.program, "model");
        //        GLint viewlLoc = glGetUniformLocation(lightshader.program, "view");
        //        GLint projectionLoc = glGetUniformLocation(lightshader.program, "projection");
        //        GLint objColorLoc = glGetUniformLocation(lightshader.program, "objColor");
        //        GLint lightColorLoc = glGetUniformLocation(lightshader.program, "lightColor");
        
        //        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        //        glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(view));
        //        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        //        glUniform3f(objColorLoc, 1.0f, 0.5f, 0.31f);
        //        glUniform3f(lightColorLoc,  1.0f, 1.0f, 1.0f);
        
        //        block.bindTexture();
        //        glBindVertexArray(VAO_Light);
        //        light.bindVAO();
        //        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        
        //        model = glm::translate(model, glm::vec3(1.2f, 1.0f, 2.0f));
        //        model = glm::scale(model, glm::vec3(0.2f));
    }
    
    GLint modelLoc = glGetUniformLocation(shader.program, "model");
    GLint viewlLoc = glGetUniformLocation(shader.program, "view");
    GLint projectionLoc = glGetUniformLocation(shader.program, "projection");
    
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewlLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
    
    shader.Use();
    object.bindVAO();
//    texture.bindTexture();
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
