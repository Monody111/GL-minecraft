//
//  Mesh.hpp
//  GL
//
//  Created by Chen.Zr on 2020/1/28.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <GL/glew.h>
#include <vector>

struct Mesh
{
    std::vector<GLfloat> vertexPositions;
    std::vector<GLfloat> textureCoords;
    std::vector<GLuint>  indices;
};

#endif /* Mesh_hpp */
