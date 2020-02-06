//
//  Mesh.cpp
//  GL
//
//  Created by Chen.Zr on 2020/2/6.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "Mesh.hpp"


Mesh::Mesh(std::vector<Vertex> vertices,
           std::vector<GLuint> indices,
           std::vector<BasicTexture> textures) {
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    this->setupMesh();
}

//Mesh::~Mesh() {
//    deleteData();
//}

void Mesh::bindVAO() {
    glBindVertexArray(VAO);
}

//void Mesh::createVAO(){
//    if (VAO != 0) {
//        deleteData();
//    }
//    glGenVertexArrays(1, &VAO);
//}

//void Mesh::deleteData() {
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    VAO = 0;
//}

//void Mesh::addVBO(int dimensions, const std::vector<GLfloat>& data) {
//    GLuint VBO;
//    glBindVertexArray(VAO);
//    glGenBuffers(1, &VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
//    glVertexAttribPointer(VBOCount, dimensions, GL_FLOAT, GL_FALSE, dimensions * sizeof(GLfloat), (GLvoid*)0);
//
//    glEnableVertexAttribArray(VBOCount++);
//    glBindVertexArray(0);
//    VBOs.push_back(VBO);
//}

//void Mesh::addEBO(const std::vector<GLint> &indices) {
//    GLuint EBO;
//    glBindVertexArray(VAO);
//    glGenBuffers(1, &EBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLint), indices.data(), GL_STATIC_DRAW);
//    glBindVertexArray(0);
//}

void Mesh::addInstanceVBO(int dimensions,
                          const std::vector<glm::vec3> &data) {
    GLuint instanceVBO;
    glBindVertexArray(VAO);
    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(VBOCount, dimensions, GL_FLOAT, GL_FALSE, dimensions * sizeof(GLfloat), (GLvoid*)0);
    
    glVertexAttribDivisor(2, 1);
    
    glEnableVertexAttribArray(VBOCount++);
    glBindVertexArray(0);
    
//    VBOs.push_back(instanceVBO);
}

void Mesh::setupMesh() {
    
    glGenVertexArrays(1, &VAO);
    
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(GL_ARRAY_BUFFER,
                 this->vertices.size() * sizeof(Vertex),
                 &this->vertices[0], GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 this->indices.size() * sizeof(GLuint),
                 &this->indices[0], GL_STATIC_DRAW);

    // 设置顶点坐标指针
    glEnableVertexAttribArray(VBOCount);
    glVertexAttribPointer(VBOCount++, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex),(GLvoid*)0);
    // 设置法线指针
    glEnableVertexAttribArray(VBOCount);
    glVertexAttribPointer(VBOCount++, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, normal));
    // 设置顶点的纹理坐标
    glEnableVertexAttribArray(VBOCount);
    glVertexAttribPointer(VBOCount++, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                          (GLvoid*)offsetof(Vertex, texCroods));

    glBindVertexArray(0);
}






