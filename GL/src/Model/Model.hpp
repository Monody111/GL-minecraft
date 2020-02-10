////
////  Model.hpp
////  GL
////
////  Created by Chen.Zr on 2020/2/9.
////  Copyright © 2020 Chen.Zr. All rights reserved.
////
//
//#ifndef Model_hpp
//#define Model_hpp
//
//#include <string>
//#include <vector>
//#include <GL/glew.h>
//#include <glm/glm.hpp>
//
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>
//
//#include "Mesh.hpp"
//#include "BasicTexture.hpp"
//
//class Mesh;
//
//class Model
//{
//    public:
//
//        Model(GLchar* path)
//        {
//            this->loadModel(path);
//        }
//    private:
//
//        std::vector<Mesh> meshes;
//        std::string directory;
//
//        void loadModel(std::string path);
//        void processNode(aiNode* node, const aiScene* scene);
//        Mesh processMesh(aiMesh* mesh, const aiScene* scene);
//        std::vector<BasicTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
//};
//
//#endif /* Model_hpp */
