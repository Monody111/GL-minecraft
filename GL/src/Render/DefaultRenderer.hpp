//
//  DefaultRenderer.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef DefaultRenderer_hpp
#define DefaultRenderer_hpp

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Renderer.hpp"
#include "BaseComponent.hpp"
#include "BasicTexture.hpp"
#include "Camera.hpp"

class DefaultRenderer: public Renderer{
public:
    std::string name = "DefaultRenderer";
    
    DefaultRenderer(const std::string &vertShaderName,
                    const std::string &fragShaderName):
    Renderer(vertShaderName, fragShaderName){};
    void render(BasicTexture *t) override;

    ~DefaultRenderer(){};
};

#endif /* DefaultRenderer_hpp */
