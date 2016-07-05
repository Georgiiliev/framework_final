//
//  scene.hpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#ifndef scene_hpp
#define scene_hpp

#include <stdio.h>
#include <vector>
#include "gameobject.hpp"

class Scene{
public:
    Scene();
    ~Scene();
    
    void addGameObject(GameObject* gameObject);
    virtual void update(float deltaTime);

    std::vector<GameObject*> gameObjects(){return _gameObjects;}
    
private:
    std::vector<GameObject* > _gameObjects;
    
};
#endif /* scene_hpp */
