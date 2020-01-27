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

#include "Renderer.hpp"
#include "BaseComponent.hpp"

class DefaultRenderer: public Renderer{
public:
    std::string name = "DefaultRenderer";
    
    DefaultRenderer() = default;
    void render() override;
    void bindMesh(BaseComponent *mesh) override;
    void bindCamera(Camera *camera) override;
    void bindShader(Shader *shader) override;
    
    ~DefaultRenderer(){};
};

#endif /* DefaultRenderer_hpp */
