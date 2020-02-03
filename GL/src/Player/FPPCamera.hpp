//
//  FPPCamera.hpp
//  GL
//
//  Created by Chen.Zr on 2020/2/4.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef FPPCamera_hpp
#define FPPCamera_hpp

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/ext/quaternion_float.hpp>
class FPPCamera {
    
public:
    glm::vec3 position;
    glm::vec3 worldUp;
    glm::vec3 front;
    glm::vec3 right;
    glm::vec3 up;
    
    glm::Quaternion
    
    FPPCamera(glm::vec3 position);
    void updateCamera();
    void getViewMatrix() const;
    void getProjectionMatrix() const;
};

#endif /* FPPCamera_hpp */
