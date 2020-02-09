//
//  Model.cpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/3.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#include "Mesh.hpp"


Mesh::Mesh(const std::vector<GLfloat> &vertextPosition, const std::vector<GLfloat> &textureCroods){
//             , const std::vector<GLint> &indices){
    addData(vertextPosition, textureCroods);
//            , indices);
}

Mesh::~Mesh() {
    deleteData();
}

void Mesh::addData(const std::vector<GLfloat> &vertextPosition, const std::vector<GLfloat> &textureCroods){
//                    , const std::vector<GLint> &indices) {
    this -> createVAO();
    this -> bindVAO();
    addVBO(3, vertextPosition);
    addVBO(2, textureCroods);
//    addEBO(indices);
}

void Mesh::bindVAO() {
    glBindVertexArray(VAO);
//    std::cout << "Debug: " << "binding: " << VAO << std::endl;
}

void Mesh::createVAO(){
    if (VAO != 0) {
        deleteData();
        std::cout << "Debug: " << "VAO not empty delete existing VAO" << std::endl;
    }
    glGenVertexArrays(1, &VAO);
    std::cout << "Debug: " << "Create VAO" << std::endl;
}

void Mesh::deleteData() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers((GLsizei)VBOs.size(), VBOs.data());
    VBOs.clear();
    VBOCount = 0;
    VAO = 0;
}

void Mesh::addVBO(int dimensions, const std::vector<GLfloat>& data) {
    GLuint VBO;
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(VBOCount, dimensions, GL_FLOAT, GL_FALSE, dimensions * sizeof(GLfloat), (GLvoid*)0);
    
    std::cout << "Debug: " << "add VBO: " << VBO << " " << VBOCount << std::endl;
    
    glEnableVertexAttribArray(VBOCount++);
    glBindVertexArray(0);
    VBOs.push_back(VBO);
}

void Mesh::addEBO(const std::vector<GLint> &indices) {
    GLuint EBO;
    glBindVertexArray(VAO);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLint), indices.data(), GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void Mesh::addInstanceVBO(int dimensions, const std::vector<glm::vec3> &data) { 
    GLuint instanceVBO;
    glBindVertexArray(VAO);
    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(VBOCount, dimensions, GL_FLOAT, GL_FALSE, dimensions * sizeof(GLfloat), (GLvoid*)0);
    
    glVertexAttribDivisor(2, 1);
    
    std::cout << "Debug: " << "add instance VBO: " << instanceVBO << " " << VBOCount << std::endl;
    
    glEnableVertexAttribArray(VBOCount++);
    glBindVertexArray(0);
    
    VBOs.push_back(instanceVBO);
}




