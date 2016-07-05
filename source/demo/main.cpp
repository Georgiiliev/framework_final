// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/sprite.h>
#include <common/scene.hpp>
#include <common/resourcemanager.hpp>
#include <common/core.hpp>
#include "myscene.hpp"
#include "myscene01.hpp"

int main( void )
{
    Core core;
    
    MyScene* scene = new MyScene();
    MyScene01* scene2 = new MyScene01();
    
    core.addScene("main", scene);
    core.addScene("scene2", scene2);
    
    core.setActiveScene("scene2");
    
    core.run();
	return 0;
}