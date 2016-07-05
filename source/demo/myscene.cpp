//
//  myscene.cpp
//  Framework_V1
//
//  Created by Georgi Iliev on 20-06-16.
//
//

#include "myscene.hpp"

MyScene::MyScene(){
    go1 = new MyGameObject();
    go1->mesh(ResourceManager::loadMesh("../assets/models/cube.obj"));
    go1->mesh()->texture(ResourceManager::loadTexture("../assets/textures/uvmap.DDS"));
    addGameObject(go1);
    
    go2 = new MyGameObject();
    go2->mesh(ResourceManager::loadMesh("../assets/models/suzanne.obj"));
    go2->mesh()->texture(ResourceManager::loadTexture("../assets/textures/suzanne.DDS"));
    addGameObject(go2);
    
    go3 = new MyGameObject();
    go3->mesh(ResourceManager::loadMesh("../assets/models/suzanne.obj"));
    go3->mesh()->texture(ResourceManager::loadTexture("../assets/textures/suzanne.DDS"));
    addGameObject(go3);

    
    go1->position().y = -2;
    go2->position().y = 1;
    go2->position().x = 2;
    go3->position().y = 1;
    go3->position().x = -2;

    
}

MyScene::~MyScene(){
    
}

void MyScene::update(float deltaTime) {
    
    go1->rotation().y += 1 * deltaTime;
    go1->rotation().x += 1 * deltaTime;
    go2->rotation().x += 1 * deltaTime;
    go3->rotation().x -= 1 * deltaTime;
    
    Scene::update(deltaTime);
}