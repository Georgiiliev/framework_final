//
//  gameobject.hpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#ifndef gameobject_hpp
#define gameobject_hpp

#include <stdio.h>
#include "mesh.hpp"

class GameObject{
public:
    GameObject();
    ~GameObject();
    
    virtual void update(float deltaTime){};
    
    void mesh(Mesh* mesh){
        _mesh = mesh;
    }
    
    Mesh* mesh(){
        return _mesh;
    }
    
    glm::vec3& position(){return _position; }
    glm::vec3& rotation(){return _rotation; }
    glm::vec3& scale(){return _scale; }
    
private:
    Mesh* _mesh;
    
    glm::vec3 _position;
    glm::vec3 _rotation;
    glm::vec3 _scale;
    
};
#endif /* gameobject_hpp */
