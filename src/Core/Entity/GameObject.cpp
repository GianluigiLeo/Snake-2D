#include "GameObject.hpp"
#include <GL/glew.h>



/* ============================================================================================== */
/*                                           GameObject                                           */
/* ============================================================================================== */
GameObject::GameObject(const char* vertexShader, const char* fragmentShader, VertexBuffers& vertexBuffers, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color) {
    Position = position;
    Size = size;
    Rotate = rotate;
    Color = color;

    shaderObj = Shader(vertexShader, fragmentShader);

    //VBO
    glGenBuffers(2, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, vertexBuffers.VertexPosition.size() * sizeof(float), &vertexBuffers.VertexPosition[0], GL_STATIC_DRAW);

    
    //VAO
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    //unbind 
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
}

/* ============================================================================================== */
/*                                           GameObject                                           */
/* ============================================================================================== */
// GameObject::GameObject(const char* vertexShader, const char* fragmentShader, VertexBuffers& vertexBuffers, TextureSettings& textureSettings, glm::vec2 position, glm::vec2 size, float rotate, float velocity, glm::vec3 color) {
//     Position = position;
//     Size = size;
//     Rotate = rotate;
//     Velocity = velocity;
//     Color = color;

//     shaderObj = Shader(vertexShader, fragmentShader);

//     //VBO
//     glGenBuffers(2, vbo);
    
//     //Vbo Bind vertexPosition
//     glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
//     glBufferData(GL_ARRAY_BUFFER, vertexBuffers.VertexPosition.size() * sizeof(float), &vertexBuffers.VertexPosition[0], GL_STATIC_DRAW);

//     //Vbo Bind vertexTexture
//     glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
//     glBufferData(GL_ARRAY_BUFFER, vertexBuffers.VertexTexture.size() * sizeof(float), &vertexBuffers.VertexTexture[0], GL_DYNAMIC_DRAW);

    
//     //VAO
//     glGenVertexArrays(1,&vao);
//     glBindVertexArray(vao);
//     //VertexPosition
//     glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
//     glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     //TexturePosition
//     glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
//     glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(1);

//     //Texture
//     textureObj.Load(textureSettings);


//     //unbind 
//     glBindVertexArray(0);
//     glBindBuffer(GL_ARRAY_BUFFER, 0);
// }

/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void GameObject::onRenderer(glm::mat4 projection) {


     //Texture
    // glActiveTexture(GL_TEXTURE0);
    // textureObj.Bind();

    //Shader Use
    shaderObj.Use();


    //Projection
    shaderObj.setMat4("projection", projection);

    //Set Color
    shaderObj.setVec3("customColor", Color);
    
    //Model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(Position.x, Position.y, 0.0f));//Position  
    // model = glm::translate(model, glm::vec3(0.5f * Size.x, 0.5f * Size.y, 0.0f)); // move origin of rotation to center of quad -- Rotation
    model = glm::rotate(model, glm::radians(Rotate), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate -- Rotation
    // model = glm::translate(model, glm::vec3(-0.5f * Size.x, -0.5f * Size.y, 0.0f)); // move origin back -- Rotation 
    model = glm::scale(model, glm::vec3(Size.x, Size.y, 1.0f)); // Size -- Scale
    shaderObj.setMat4("model", model);

    //Disegna Object
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);

}

/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void GameObject::onDestroy() {

    shaderObj.onDestroy();
    glDeleteBuffers(1, vbo);
    glDeleteVertexArrays(1, &vao);

}