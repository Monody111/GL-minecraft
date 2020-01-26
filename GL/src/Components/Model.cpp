//
//  Model.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/3.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#include "./Model.hpp"


Model::Model(const std::vector<GLfloat> &vertextPosition, const std::vector<GLfloat> &textureCroods){
//             , const std::vector<GLint> &indices){
    addData(vertextPosition, textureCroods);
//            , indices);
}

Model::~Model() { 
    deleteData();
}

void Model::addData(const std::vector<GLfloat> &vertextPosition, const std::vector<GLfloat> &textureCroods){
//                    , const std::vector<GLint> &indices) {
    if (VAO != 0) {
        deleteData();
    }
//    glewExperimental = GL_TRUE;
//    glewInit();
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    addVBO(3, vertextPosition);
    addVBO(2, textureCroods);
//    addEBO(indices);
}

void Model::bindVAO() { 
    glBindVertexArray(VAO);
}

void Model::deleteData() { 
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers((GLsizei)VBOs.size(), VBOs.data());
    VBOs.clear();
    VBOCount = 0;
    VAO = 0;
}

void Model::addVBO(int dimensions, const std::vector<GLfloat>& data) {
    GLuint VBO = 0;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(VBOCount, dimensions, GL_FLOAT, GL_FALSE, dimensions * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(VBOCount++);
    VBOs.push_back(VBO);
}

void Model::addEBO(const std::vector<GLint> &indices) { 
    GLuint EBO = 0;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLint), indices.data(), GL_STATIC_DRAW);
}



