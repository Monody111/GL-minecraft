//
//  Section.cpp
//  GL
//
//  Created by Chen.Zr on 2020/1/31.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#include "Section.hpp"

Section::Section(){
    
    std::vector<glm::vec3> translations;
    
    for(int y = 0; y < 16; y++){
        for(int x = 0; x < 16; x++){
            for(int z = 0; z < 16; z++){
                translations.push_back(glm::vec3(x, y, z));
            }
        }
    }
    
    model = new Model();
    model -> createVAO();
    model -> bindVAO();
    model -> addVBO(3, vertextPosition);
    model -> addVBO(2, textureCroods);
    model -> addInstanceVBO(3, translations);
}
