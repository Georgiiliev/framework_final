//
//  myscene01.hpp
//  Framework_V1
//
//  Created by Georgi Iliev on 20-06-16.
//
//

#ifndef myscene01_hpp
#define myscene01_hpp

#include <stdio.h>
#include "common/scene.hpp"
#include "common/resourcemanager.hpp"
#include "mygameobject.hpp"

class MyScene01 : public Scene{
public:
    MyScene01();
    ~MyScene01();
    
    void update(float deltaTime) override;
    
private:
    MyGameObject* go1;
    MyGameObject* go2;
    MyGameObject* go3;
    
};
#endif /* myscene01_hpp */

