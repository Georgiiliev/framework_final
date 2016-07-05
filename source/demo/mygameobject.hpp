//
//  mygameobject.hpp
//  Framework_V1
//
//  Created by Georgi Iliev on 20-06-16.
//
//

#ifndef mygameobject_hpp
#define mygameobject_hpp

#include <stdio.h>
#include "common/gameobject.hpp"

class MyGameObject : public GameObject{
public:
    MyGameObject();
    ~MyGameObject();
    
    void update(float deltaTime) override;

private:
    
};
#endif /* mygameobject_hpp */
