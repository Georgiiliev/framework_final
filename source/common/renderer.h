#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/shader.hpp>
#include <common/sprite.h>
#include <common/texture.h>
#include <common/camera.h>
#include <common/mesh.hpp>
#include <common/scene.hpp>

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void renderSprite(Sprite* sprite);
    void renderMesh(Mesh* mesh, glm::vec3 postion, glm::vec3 rotation, glm::vec3 scale);
    
    void renderScene(Scene* scene);
    void renderGameobject(GameObject* gameObject);
    
    GLFWwindow* window() { return _window; };
    
    int init();

private:
		
    void bindMesh(Mesh* mesh);
    void unbindMesh();
    
    GLFWwindow* _window;
		
    int _window_width;
    int _window_height;

    std::string _fragment_shader;
    std::string _vertex_shader;

    GLuint _programID;
    GLuint _vertexPosition_modelspaceID;
    GLuint _vertexUVID;
    GLuint _matrixID;
    GLuint _textureID;
    GLuint _viewMatrixID;
    GLuint _modelMatrixID;

    glm::mat4 _projection;
    glm::mat4 _view;
};

#endif /* RENDERER_H */
