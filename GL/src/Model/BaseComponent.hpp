//
//  BaseComponet.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef BaseComponet_hpp
#define BaseComponet_hpp

#include "Mesh.hpp"
#include <glm/glm.hpp>

class BaseComponent {
    
public:
    Mesh *mesh = nullptr;
    
    inline Mesh *getComponentModel(){
        if(mesh){
            return mesh;
        }else{
            throw std::runtime_error("invalid model pointer");
        }
    }
    virtual ~BaseComponent(){};
};

#endif /* BaseComponet_hpp */
