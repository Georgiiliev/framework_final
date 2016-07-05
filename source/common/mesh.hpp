//
//  mesh.hpp
//  RT2D
//
//  Created by Georgi Iliev on 15-06-16.
//
//

#ifndef mesh_hpp
#define mesh_hpp

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include "texture.h"

using namespace std;

class Mesh{
    
public:
    Mesh();
    ~Mesh();
    
    GLuint vertexbuffer() { return _vertexbuffer; }
    GLuint uvbuffer() { return _uvbuffer; }
    GLuint normalbuffer() {return _normalbuffer; }
    
    void generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv, std::vector<glm::vec3>& normal);
    void texture(Texture* texture){ _texture = texture; }
    
    Texture* texture(){return _texture; }
    
    int numverts() {return _numverts;}
    
private:
    GLuint _vertexbuffer;
    GLuint _uvbuffer;
    GLuint _normalbuffer;
    
    Texture* _texture;
    unsigned int _numverts;
    

};

#endif /* mesh_hpp */
