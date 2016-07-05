//
//  myscene.hpp
//  Framework_V1
//
//  Created by Georgi Iliev on 20-06-16.
//
//

#ifndef myscene_hpp
#define myscene_hpp

#include <stdio.h>
#include "common/scene.hpp"
#include "common/resourcemanager.hpp"
#include "mygameobject.hpp"

class MyScene : public Scene{
public:
    MyScene();
    ~MyScene();
    
    void update(float deltaTime) override;
    
private:
    MyGameObject* go1;
    MyGameObject* go2;
    MyGameObject* go3;

};
#endif /* myscene_hpp */
