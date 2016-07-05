//
//  scene.cpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#include "scene.hpp"

Scene::Scene(){

}

Scene::~Scene(){

}

void Scene::addGameObject(GameObject *gameObject){
    _gameObjects.push_back(gameObject);
    
}

void Scene::update(float deltaTime){
    for(GameObject* gameobject : _gameObjects){
        gameobject->update(deltaTime);
    }
}