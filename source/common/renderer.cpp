#include <common/renderer.h>

Renderer::Renderer()
{
    _window_width = 1280;
    _window_height = 720;

    _fragment_shader	= "../assets/shaders/sprite.frag";
    _vertex_shader	= "../assets/shaders/sprite.vert";

    this->init();
}

Renderer::~Renderer()
{
    // Cleanup VBO and shader
	glDeleteProgram(_programID);
	glDeleteTextures(1, &_textureID);
}

int Renderer::init()
{
    if( !glfwInit() ) {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    _window = glfwCreateWindow( 1024, 900, "Framework_v1.0", NULL, NULL);
    if( _window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(_window);
    
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    
    //glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);
    //glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    glfwPollEvents();
    glfwSetCursorPos(_window, 1024/2, 768/2);
    
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    glEnable(GL_CULL_FACE);
    
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    _programID = LoadShaders( "../assets/shaders/StandardShading.vertexshader",
                             "../assets/shaders/StandardShading.fragmentshader" );
    
    _matrixID = glGetUniformLocation(_programID, "MVP");
    _viewMatrixID = glGetUniformLocation(_programID, "V");
    _modelMatrixID = glGetUniformLocation(_programID, "M");
    _textureID  = glGetUniformLocation(_programID, "myTextureSampler");
    
    _projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    
    _view = glm::lookAt(glm::vec3(0,2,6), glm::vec3(0,0,0), glm::vec3(0,1,0));
    
    return 0;
}


void Renderer::renderMesh(Mesh* mesh, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale){
    
    glm::mat4 translationMatrix  = glm::translate(glm::mat4(1.0f), position);
    glm::mat4 rotationMatrix  = glm::eulerAngleYXZ(rotation.x, rotation.y, rotation.z);
    glm::mat4 scalingMatrix    = glm::scale(glm::mat4(1.0f), scale);
    
    glm::mat4 mm = translationMatrix * rotationMatrix * scalingMatrix;
    
    glm::mat4 MVP = _projection * _view * mm;
    glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &MVP[0][0]);
    
    glUniformMatrix4fv(_matrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(_modelMatrixID, 1, GL_FALSE, &mm[0][0]);
    glUniformMatrix4fv(_viewMatrixID, 1, GL_FALSE, &_view[0][0]);
    
    GLuint LightID = glGetUniformLocation(_programID, "LightPosition_worldspace");
    
    glm::vec3 lightPos = glm::vec3(4,4,4);
    glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
    
    bindMesh(mesh);
    
    glActiveTexture(GL_TEXTURE0);
    if(mesh->texture()){
        glBindTexture(GL_TEXTURE_2D, mesh->texture()->textureID());
    } else {
        
    }
    
    glDrawArrays(GL_TRIANGLES, 0, mesh->numverts());
    
    unbindMesh();
    
}

void Renderer::renderScene(Scene* scene){
    
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(_programID);
    glUniform1i(_textureID, 0);
    
    for(GameObject* gameObject : scene->gameObjects()){
        renderGameobject(gameObject);
    }
    
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void Renderer::renderGameobject(GameObject *gameObject){
    if(gameObject->mesh()) {
        renderMesh(gameObject->mesh(), gameObject->position(), gameObject->rotation(), gameObject->scale());
    }
}

void Renderer::bindMesh(Mesh *mesh){
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexbuffer());
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0, (void*)0 );
    
    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->uvbuffer());
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    
    // 3rd attribute buffer : normals
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->normalbuffer());
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
}

void Renderer::unbindMesh(){
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

}


void Renderer::renderSprite(Sprite* sprite)
{
//    // Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
//    computeMatricesFromInputs(_window);
//    
//    glm::vec3 cursor = getCursor();
//    //printf("(%f,%f)\n",cursor.x, cursor.y);
//    
//    glm::mat4 ViewMatrix = getViewMatrix(); // get from Camera (Camera position and direction)
//    glm::mat4 ModelMatrix = glm::mat4(1.0f);
//    
//    // Use our shader
//    glUseProgram(programID);
//    
//    // Build the Model matrix
//    glm::mat4 translationMatrix	= glm::translate(glm::mat4(1.0f), glm::vec3(500.0f, 300.0f, 0.0f));
//    glm::mat4 rotationMatrix	= glm::eulerAngleYXZ(0.0f, 0.0f, 0.0f);
//    glm::mat4 scalingMatrix		= glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//    
//    ModelMatrix = translationMatrix * rotationMatrix * scalingMatrix;
//    
//    glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
//    
//    // Send our transformation to the currently bound shader,
//    // in the "MVP" uniform
//    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
//    
//    // Bind our texture in Texture Unit 0
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, sprite->texture());
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // Set our "myTextureSampler" sampler to user Texture Unit 0
//    glUniform1i(textureID, 0);
//    
//    // 1st attribute buffer : vertices
//    glEnableVertexAttribArray(vertexPosition_modelspaceID);
//    glBindBuffer(GL_ARRAY_BUFFER, sprite->vertexbuffer());
//    glVertexAttribPointer(
//                          vertexPosition_modelspaceID,  // The attribute we want to configure
//                          3,							// size : x+y+z => 3
//                          GL_FLOAT,					 // type
//                          GL_FALSE,					 // normalized?
//                          0,							// stride
//                          (void*)0					  // array buffer offset
//                          );
//    
//    // 2nd attribute buffer : UVs
//    glEnableVertexAttribArray(vertexUVID);
//    glBindBuffer(GL_ARRAY_BUFFER, sprite->uvbuffer());
//    glVertexAttribPointer(
//                          vertexUVID,				   // The attribute we want to configure
//                          2,							// size : U+V => 2
//                          GL_FLOAT,					 // type
//                          GL_FALSE,					 // normalized?
//                          0,							// stride
//                          (void*)0					  // array buffer offset
//                          );
//    
//    // Draw the triangles !
//    glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles
//    
//    glDisableVertexAttribArray(vertexPosition_modelspaceID);
//    glDisableVertexAttribArray(vertexUVID);
}




