//
//  BaseComponet.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef BaseComponet_hpp
#define BaseComponet_hpp

#include <string>
#include <vector>
#include <glm/glm.hpp>

#include "Model.hpp"

class BaseComponent {
    
public:
    Model *model;
//    virtual ~BaseComponent(){};
    virtual Model *getComponentModel();
};

#endif /* BaseComponet_hpp */
