#include "Ball.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

/* ============================================================================================== */
/*                                             Player                                             */
/* ============================================================================================== */
Ball::Ball(glm::vec2 position, glm::vec2 size, float rotate, float velocity) {
    Position = position;
    Size = size;
    Rotate = rotate;
    Velocity = velocity;
    Color = glm::vec3(1.0, 1.0, 1.0);

    VertexBuffers vertexBuff;
    vertexBuff.VertexPosition = {
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };
    vertexBuff.VertexTexture = {
        0.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,

        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0
    };

    TextureSettings textSettings;
    textSettings.imagePath = "res/image/ball.png";
    textSettings.Format = GL_RGBA;
    textSettings.Wrap_S = GL_REPEAT;
    textSettings.Wrap_T = GL_REPEAT;
    textSettings.Filter_Min = GL_LINEAR_MIPMAP_LINEAR;
    textSettings.Filter_Max = GL_LINEAR;


    ballObj = GameObject(   "res/shaders/vert.glsl",
                            "res/shaders/frag.glsl",
                            vertexBuff,
                            textSettings,
                            Position,
                            Size,
                            Rotate,
                            Velocity,
                            Color
                            );
}



/* ============================================================================================== */
/*                                            onUpdate                                            */
/* ============================================================================================== */
void Ball::onUpdate() {

    //Mostra posizione
    std::cout << "Ball: || " << "X:" << ballObj.Position.x << " || Y:" << ballObj.Position.y << std::endl;

    if(ballObj.Position.x <= 0.32f){
        ballObj.Position.x = 0.0f;
    }
    if(ballObj.Position.x >= 800.0f - ballObj.Size.x){
        ballObj.Position.x = 800.0f - ballObj.Size.x;
    }
}

/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void Ball::onRenderer(glm::mat4 projection){

    this->onUpdate();

    ballObj.onRenderer(projection);
}




/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Ball::onDestroy() {

    ballObj.onDestroy();

}



/* ============================================================================================== */
/*                                             onMove                                             */
/* ============================================================================================== */
void Ball::onMove(float dt){
    
    ballObj.Position-- * dt;
}


/* ============================================================================================== */
/*                                             onInput                                            */
/* ============================================================================================== */
void Ball::onInput(bool Keys[], float dt) {

    float velocity = Velocity * dt;

    if(Keys[GLFW_KEY_A]){
        ballObj.Position.x -= velocity;
        
    }

    if(Keys[GLFW_KEY_D]){
        ballObj.Position.x += velocity;
       
    }
    if(Keys[GLFW_KEY_W]){
        ballObj.Position.y -= velocity;
       
    }
    if(Keys[GLFW_KEY_S]){
        ballObj.Position.y += velocity;
       
    }
}