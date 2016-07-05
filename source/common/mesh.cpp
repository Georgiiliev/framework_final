//
//  mesh.cpp
//  RT2D
//
//  Created by Georgi Iliev on 15-06-16.
//
//

#include "mesh.hpp"

Mesh::Mesh(){
    _vertexbuffer = 0;
    _uvbuffer = 0;
    _numverts = 0;
    _texture = nullptr;
}

Mesh::~Mesh(){

}

void Mesh::generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv, std::vector<glm::vec3>& normal)
{
    //create GLuint _vertexbuffer;
    glGenBuffers(1, &_vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(glm::vec3), &vertex[0], GL_STATIC_DRAW);
    
    //create GLuint _normalbuffer;
    glGenBuffers(1, &_normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(glm::vec3), &normal[0], GL_STATIC_DRAW);
    
    //create GLuint _uvbuffer;
    glGenBuffers(1, &_uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(glm::vec2), &uv[0], GL_STATIC_DRAW);
    
    _numverts = vertex.size();
}