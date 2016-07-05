//
//  gameobject.cpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#include "gameobject.hpp"

GameObject::GameObject(){
    _mesh = nullptr;
    
    _position = glm::vec3(0,0,0);
    _rotation = glm::vec3(0,0,0);
    _scale = glm::vec3(1,1,1);
    
}

GameObject::~GameObject(){

}