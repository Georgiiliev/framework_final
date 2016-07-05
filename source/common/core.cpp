//
//  core.cpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#include "core.hpp"

Core::Core(){
    _activeScene = nullptr;
}

Core::~Core(){
    
}

void Core::addScene(std::string name, Scene *scene){
    _scenes[name] = scene;
}

void Core::run(){
    do {
        if(!_activeScene){
            return;
        }
        
        calculateDeltaTime();
        _activeScene->update(_deltaTime);
        _renderer.renderScene(_activeScene);
        
    }
    
    while( glfwGetKey(_renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
          glfwWindowShouldClose(_renderer.window()) == 0 );
    
    
    glfwTerminate();
}

void Core::setActiveScene(std::string name){
    _activeScene = _scenes[name];
}

double Core::calculateDeltaTime() {
    static double lastTime = glfwGetTime();
    double startTime = glfwGetTime();
    _deltaTime = startTime - lastTime;
    lastTime = startTime;
    return _deltaTime;
}