//
//  Model.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/3.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include <GL/glew.h>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <iostream>

class Model {
    
    std::string name;
    
public:
    Model() = default;
    Model(const std::vector<GLfloat> &vertextPosition,
          const std::vector<GLfloat> &textureCroods);
//          const std::vector<GLint> &indices,);
    Model(const GLfloat *vertextPosition,
          const GLfloat *textureCroods);
//          const GLint* indices);
    ~Model();
    
    void addData(const std::vector<GLfloat> &vertextPosition,
                 const std::vector<GLfloat> &textureCroods);
//                 const std::vector<GLint> &indices);
    void createVAO();
    void bindVAO();
    void deleteData();
    
    void addVBO(int dimensions, const std::vector<GLfloat> &data);
    void addInstanceVBO(int dimensions, const std::vector<glm::vec3> &data);
    
    GLuint VAO = 0;
    int VBOCount = 0;
    std::vector<GLuint> VBOs;
    
    void addEBO(const std::vector<GLint>& indices);
};

#endif /* Model_hpp */
