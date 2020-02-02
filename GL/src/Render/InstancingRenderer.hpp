//
//  InstancingRenderer.hpp
//  GL
//
//  Created by Chen.Zr on 2020/1/31.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef InstancingRenderer_hpp
#define InstancingRenderer_hpp

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer.hpp"
#include "Model.hpp"

class InstancingRenderer: public Renderer{
public:
    std::string name = "InstancingRenderer";
    
    InstancingRenderer() = default;
    void render() override;
    void bindModel(Model *model) override;
    void bindCamera(Camera *camera) override;
    void bindShader(Shader *shader) override;
    
    ~InstancingRenderer(){};
};

#endif /* InstancingRenderer_hpp */
