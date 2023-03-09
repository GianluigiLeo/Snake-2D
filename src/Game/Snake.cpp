#include "Snake.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

/* ============================================================================================== */
/*                                              Snake                                             */
/* ============================================================================================== */
Snake::Snake(glm::vec2 position, glm::vec2 size, float rotate, float velocity, glm::vec3 color) {

    Position = position;
    Size = size;
    Rotate = rotate;
    Color = color;
    Velocity = velocity;

    VertexBuffers vertexBuff;
    vertexBuff.VertexPosition = {
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };
    // vertexBuff.VertexTexture = {
    //     0.0, 0.0,
    //     1.0, 1.0,
    //     0.0, 1.0,

    //     0.0, 0.0,
    //     1.0, 0.0,
    //     1.0, 1.0
    // };

    // TextureSettings textSettings;
    // textSettings.imagePath = "res/image/paddle.png";
    // textSettings.Format = GL_RGBA;
    // textSettings.Wrap_S = GL_REPEAT;
    // textSettings.Wrap_T = GL_REPEAT;
    // textSettings.Filter_Min = GL_LINEAR_MIPMAP_LINEAR;
    // textSettings.Filter_Max = GL_LINEAR;


    gameObj =   GameObject( "res/shaders/snakeVert.glsl",
                            "res/shaders/snakeFrag.glsl",
                            vertexBuff,
                            // textSettings,
                            Position,
                            Size,
                            Rotate,
                            Color
                            );
}



/* ============================================================================================== */
/*                                            onUpdate                                            */
/* ============================================================================================== */
void Snake::onUpdate() {

    
}

/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void Snake::onRenderer(glm::mat4 projection){

    this->onUpdate();

    gameObj.onRenderer(projection);
}


/* ============================================================================================== */
/*                                             onInput                                            */
/* ============================================================================================== */
void Snake::onInput(bool Keys[], float dt) {


    float velocity = Velocity * dt;

    if(Keys[GLFW_KEY_LEFT]){
        gameObj.Position.x -= velocity;
        
    }
    if(Keys[GLFW_KEY_RIGHT]){
        gameObj.Position.x += velocity;
       
    }
    if(Keys[GLFW_KEY_UP]){
        gameObj.Position.y -= velocity;
       
    }
    if(Keys[GLFW_KEY_DOWN]){
        gameObj.Position.y += velocity;
       
    }
}


/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Snake::onDestroy() {

    gameObj.onDestroy();

}