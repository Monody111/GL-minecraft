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
#include "BasicTexture.hpp"


class Renderer {

public:
    
    std::string name;
    Model *model = nullptr;
    Camera *camera = nullptr;
    Shader *shader = nullptr;
    
    Renderer(const std::string &vertShaderName,
             const std::string &fragShaderName){
        loadShader(vertShaderName, fragShaderName);
    }
    void virtual render(BasicTexture *t) = 0;
    void virtual bindModel(Model *model) = 0;
    void virtual bindCamera(Camera *camera) = 0;
    
    void loadShader(const std::string &vertShaderName,
                    const std::string &fragShaderName){
        shader = new Shader("Shader/" + vertShaderName,
                            "Shader/" + fragShaderName);
    }
    
    virtual ~Renderer(){};
};

#endif /* Render_hpp */
