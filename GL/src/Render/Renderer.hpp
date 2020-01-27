//
//  Render.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/18.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef Render_hpp
#define Render_hpp

#include <string>
#include "Model.hpp"
#include "Camera.hpp"
#include "Shader.hpp"
#include "BaseComponent.hpp"


class Renderer {

public:
    
    std::string name;
    Model *mesh = nullptr;
    Camera *camera = nullptr;
    Shader *shader = nullptr;
    BaseComponent *component = nullptr;
    
    Renderer() = default;
    void virtual render() = 0;
    void virtual bindMesh(BaseComponent *mesh) = 0;
    void virtual bindShader(Shader *shader) = 0;
    void virtual bindCamera(Camera *camera) = 0;
    
    virtual ~Renderer(){};
};

#endif /* Render_hpp */
