//
//  BaseComponet.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef BaseComponet_hpp
#define BaseComponet_hpp

#include "Model.hpp"
#include <glm/glm.hpp>

class BaseComponent {
    
public:
    Model *model = nullptr;
    
    inline Model *getComponentModel(){
        if(model){
            return model;
        }else{
            std::cout << "invalid model pointer" << std::endl;
            abort();
        }
    }
    virtual ~BaseComponent(){};
};

#endif /* BaseComponet_hpp */
