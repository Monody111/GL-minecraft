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
    
    void bindModel(Model *model) {
        if(model){
            this->model = model;
        }else{
            throw std::runtime_error("Unable to bind model to render: ");
        }
    }
    
    void bindCamera(Camera *camera){
        if(camera){
            this->camera = camera;
        }else{
            throw std::runtime_error("Unable to bind camera to render: ");
        }
    }
    
    void loadShader(const std::string &vertShaderName,
                    const std::string &fragShaderName){
        shader = new Shader("Shader/" + vertShaderName,
                            "Shader/" + fragShaderName);
    }
    
    virtual ~Renderer(){};
};

#endif /* Render_hpp */
