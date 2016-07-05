//
//  resourcemanager.hpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#ifndef resourcemanager_hpp
#define resourcemanager_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include "mesh.hpp"
#include "objloader.hpp"
#include "texture.h"

class ResourceManager{
    
public:
    ResourceManager();
    ~ResourceManager();
    
    static Mesh* loadMesh(std::string path);
    static Texture* loadTexture(std::string path);
    
private:
    static std::map<std::string, Mesh*> _meshes;
    static std::map<std::string, Texture*> _textures;

};
#endif /* resourcemanager_hpp */
