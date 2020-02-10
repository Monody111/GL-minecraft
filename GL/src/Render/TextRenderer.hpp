//
//  TextRenderer.hpp
//  GL
//
//  Created by Chen.Zr on 2020/2/5.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef TextRenderer_hpp
#define TextRenderer_hpp

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include <iostream>
#include <map>
#include <string>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer.hpp"
#include "GameSetting.hpp"

struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    FT_Pos Advance;    // Horizontal offset to advance to next glyph
};

class TextRenderer: public Renderer {
    
public:
    FT_Library ft;
    std::map<GLchar, Character> Characters;
    
    GLuint VAO;
    GLuint VBO;
    
    glm::mat4 projection;
    GameSetting *setting = nullptr;
    
    TextRenderer(const std::string &vertShaderName,
                 const std::string &fragShaderName,
                 GameSetting *setting);
    void render(BasicTexture *t) override;
    void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
    void loadFT();
    void loadModel();
};

#endif /* TextRenderer_hpp */
