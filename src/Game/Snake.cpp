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


    //Snake -- HEAD
    gameObj[0] =   GameObject(  "res/shaders/snakeVert.glsl",
                                "res/shaders/snakeFrag.glsl",
                                vertexBuff,
                                // textSettings,
                                Position,
                                Size,
                                Rotate,
                                Color
                            );

    //Snake -- BODY
    gameObj[1] =   GameObject(  "res/shaders/snakeVert.glsl",
                                "res/shaders/snakeFrag.glsl",
                                vertexBuff,
                                // textSettings,
                                glm::vec2(Position.x + Size.x, Position.y),
                                Size,
                                Rotate,
                                Color
                            );

    //Snake -- TAIL
    gameObj[2] =   GameObject(  "res/shaders/snakeVert.glsl",
                                "res/shaders/snakeFrag.glsl",
                                vertexBuff,
                                // textSettings,
                                glm::vec2(Position.x + Size.x * 2, Position.y),
                                Size,
                                Rotate,
                                Color
                            );

    Snake_Parts = {
        gameObj[0], //HEAD
        gameObj[1], //BODY
        gameObj[2], //TAIL
    };
}



/* ============================================================================================== */
/*                                            onUpdate                                            */
/* ============================================================================================== */
void Snake::onUpdate() {

    // Snake_Parts.push_back(gameObj[0]);
}

/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void Snake::onRenderer(glm::mat4 projection){

    this->onUpdate();

    for(auto &snakeParts : Snake_Parts){
        snakeParts.onRenderer(projection);
    }
}


/* ============================================================================================== */
/*                                             onInput                                            */
/* ============================================================================================== */
void Snake::onInput(bool Keys[], float dt) {


    float velocity = Velocity * dt;
    

    if(Keys[GLFW_KEY_LEFT]){
        if(Snake_Parts.at(0).Position.x -= velocity){
            Snake_Parts.at(1).Position = glm::vec2(Snake_Parts.at(0).Position.x + Size.x, Snake_Parts.at(0).Position.y);
            Snake_Parts.at(2).Position = glm::vec2(Snake_Parts.at(1).Position.x + Size.x, Snake_Parts.at(1).Position.y);
            
        }

        
        
    }
        
    
    if(Keys[GLFW_KEY_RIGHT]){
        if(Snake_Parts.at(0).Position.x += velocity){
            Snake_Parts.at(1).Position = glm::vec2(Snake_Parts.at(0).Position.x - Size.x, Snake_Parts.at(0).Position.y);
            Snake_Parts.at(2).Position = glm::vec2(Snake_Parts.at(1).Position.x - Size.x, Snake_Parts.at(1).Position.y);
        }
       
    }
    if(Keys[GLFW_KEY_UP]){
        if(Snake_Parts.at(0).Position.y -= velocity){
            Snake_Parts.at(1).Position = glm::vec2(Snake_Parts.at(0).Position.x, Snake_Parts.at(0).Position.y + Size.y);
            Snake_Parts.at(2).Position = glm::vec2(Snake_Parts.at(1).Position.x, Snake_Parts.at(1).Position.y + Size.y);
        }

       
    }
    if(Keys[GLFW_KEY_DOWN]){
        if(Snake_Parts.at(0).Position.y += velocity){
            Snake_Parts.at(1).Position = glm::vec2(Snake_Parts.at(0).Position.x, Snake_Parts.at(0).Position.y - Size.y);
            Snake_Parts.at(2).Position = glm::vec2(Snake_Parts.at(1).Position.x, Snake_Parts.at(1).Position.y - Size.y);

        }
       
    }
}


/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Snake::onDestroy() {

    // gameObj[0].onDestroy();
    for(auto &snakeParts : Snake_Parts){
        snakeParts.onDestroy();
    }

}