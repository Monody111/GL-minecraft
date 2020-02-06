//
//  Mesh.hpp
//  GL
//
//  Created by Chen.Zr on 2020/2/6.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <glm/glm.hpp>
#include <vector>
#include <GL/glew.h>

#include "BasicTexture.hpp"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCroods;
};

class Mesh {
    
public:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<BasicTexture> textures;
    
//    std::vector<GLuint> VBOs;
    
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
    int VBOCount = 0;
    
    
    Mesh(std::vector<Vertex> vertices,
         std::vector<GLuint> indices,
         std::vector<BasicTexture> textures);
    
//    ~Mesh();
    
//    void createVAO();
    void bindVAO();
//    void deleteData();
    
//    void addVBO(int dimensions, const std::vector<GLfloat> &data);
    void addInstanceVBO(int dimensions, const std::vector<glm::vec3> &data);
    
//    void addEBO(std::vector<GLint> indices);
    
    void setupMesh();
};

#endif /* Mesh_hpp */
