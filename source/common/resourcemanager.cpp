//
//  resourcemanager.cpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#include "resourcemanager.hpp"

std::map<std::string, Mesh* > ResourceManager::_meshes;

std::map<std::string, Texture* > ResourceManager::_textures;


ResourceManager::ResourceManager(){

}

ResourceManager::~ResourceManager(){
    
}

Mesh* ResourceManager::loadMesh(std::string path){
    if(_meshes[path] != nullptr){
        return _meshes[path];
    }
    
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    
    loadOBJ(path.c_str(), vertices, uvs, normals);
    
    Mesh* mesh = new Mesh();
    
    mesh->generateBuffers(vertices, uvs, normals);
    
    _meshes[path] = mesh;
    
    return mesh;
}
Texture* ResourceManager::loadTexture(std::string path){
    if(_textures[path] != nullptr){
        return _textures[path];
    }

    Texture* texture = new Texture(loadDDS(path.c_str()));
    
    _textures[path] = texture;
    
    return texture;
}