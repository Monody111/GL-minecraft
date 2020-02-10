////
////  Model.cpp
////  GL
////
////  Created by Chen.Zr on 2020/2/9.
////  Copyright © 2020 Chen.Zr. All rights reserved.
////
//
//#include "Model.hpp"
//
//
//void Model::loadModel(std::string path) { 
//    Assimp::Importer importer;
//    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
//    
//    if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
//    {
//        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
//        return;
//    }
//    this->directory = path.substr(0, path.find_last_of('/'));
//
//    this->processNode(scene->mRootNode, scene);
//}
//
//void Model::processNode(aiNode *node, const aiScene *scene) {
//    // 添加当前节点中的所有Mesh
//    for(GLuint i = 0; i < node->mNumMeshes; i++)
//    {
//        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
//        this->meshes.push_back(this->processMesh(mesh, scene));
//    }
//    // 递归处理该节点的子孙节点
//    for(GLuint i = 0; i < node->mNumChildren; i++)
//    {
//        this->processNode(node->mChildren[i], scene);
//    }
//}
//
//Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene) { 
//    std::vector<glm::vec3> vertices;
//    std::normal<GLfloat> normals;
//    std::vector<GLuint> indices;
//    std::vector<BasicTexture> textures;
//
//    for(GLuint i = 0; i < mesh->mNumVertices; i++)
//    {
////        Vertex vertex;
//        // 处理顶点坐标、法线和纹理坐标
//        glm::vec3 vector;
//        vector.x = mesh->mVertices[i].x;
//        vector.y = mesh->mVertices[i].y;
//        vector.z = mesh->mVertices[i].z;
////        vertex.Position = vector;
//        
//        vertices.push_back(vector);
//    }
//    // 处理顶点索引
////    ...
//    // 处理材质
//    if(mesh->mMaterialIndex >= 0)
//    {
//        ...
//    }
//
//    return Mesh(vertices, indices, textures);
//}
//
////std::vector<BasicTexture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName) {
////    <#code#>;
////}
