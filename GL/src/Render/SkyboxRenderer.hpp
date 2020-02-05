//
//  SkyboxRenderer.hpp
//  GL
//
//  Created by Chen.Zr on 2020/2/3.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef SkyboxRenderer_hpp
#define SkyboxRenderer_hpp

#include <string>
#include <vector>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer.hpp"
#include "CubeTexture.hpp"

class SkyboxRenderer: public Renderer{
    public:
        std::string name = "CubeRenderer";
        CubeTexture *cubetexture = nullptr;
        
        GLfloat SIZE = 1;
        std::vector<GLfloat> vertextPosition{
            -SIZE,  SIZE, -SIZE,
            -SIZE, -SIZE, -SIZE,
             SIZE, -SIZE, -SIZE,
             SIZE, -SIZE, -SIZE,
             SIZE,  SIZE, -SIZE,
            -SIZE,  SIZE, -SIZE,

            -SIZE, -SIZE,  SIZE,
            -SIZE, -SIZE, -SIZE,
            -SIZE,  SIZE, -SIZE,
            -SIZE,  SIZE, -SIZE,
            -SIZE,  SIZE,  SIZE,
            -SIZE, -SIZE,  SIZE,

             SIZE, -SIZE, -SIZE,
             SIZE, -SIZE,  SIZE,
             SIZE,  SIZE,  SIZE,
             SIZE,  SIZE,  SIZE,
             SIZE,  SIZE, -SIZE,
             SIZE, -SIZE, -SIZE,

            -SIZE, -SIZE,  SIZE,
            -SIZE,  SIZE,  SIZE,
             SIZE,  SIZE,  SIZE,
             SIZE,  SIZE,  SIZE,
             SIZE, -SIZE,  SIZE,
            -SIZE, -SIZE,  SIZE,

            -SIZE,  SIZE, -SIZE,
             SIZE,  SIZE, -SIZE,
             SIZE,  SIZE,  SIZE,
             SIZE,  SIZE,  SIZE,
            -SIZE,  SIZE,  SIZE,
            -SIZE,  SIZE, -SIZE,

            -SIZE, -SIZE, -SIZE,
            -SIZE, -SIZE,  SIZE,
             SIZE, -SIZE, -SIZE,
             SIZE, -SIZE, -SIZE,
            -SIZE, -SIZE,  SIZE,
             SIZE, -SIZE,  SIZE
        };
        
        SkyboxRenderer(const std::string &vertShaderName,
                       const std::string &fragShaderName);
        void loadModel();
        void loadTexture();
        void renderSky();
    
        void render(BasicTexture *t) override;
};

#endif /*enderer_hpp */
