//
//  CubeRenderer.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2019/11/5.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//

#ifndef CubeRenderer_hpp
#define CubeRenderer_hpp

#include <glm/glm.hpp>
#include <vector>
#include <GL/glew.h>
#include "Model.hpp"
#include "Shader.hpp"
#include "Camera.hpp"

class CubeRenderer {
    
public:
    CubeRenderer();
    
//    void add(const glm::vec3& position);
    
    void render(const Camera& camera);
    
private:
//    Texture texture;
    Model object;
    Shader shader;
};
#endif /* CubeRenderer_hpp */
