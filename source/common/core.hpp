//
//  core.hpp
//  Framework_V1
//
//  Created by Georgi Iliev on 16-06-16.
//
//

#ifndef core_hpp
#define core_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "scene.hpp"
#include "renderer.h"

class Core{
public:
    Core();
    ~Core();
    
    void addScene(std::string, Scene* scene);
    std::map<std::string, Scene* > scenes(){return _scenes;}
    
    void run();
    void setActiveScene(std::string name);
    double calculateDeltaTime();
    
private:
    
    std::map<std::string, Scene* > _scenes;
    Scene* _activeScene;
    Renderer _renderer;
    float _deltaTime;

};
#endif /* core_hpp */
