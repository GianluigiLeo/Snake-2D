#include "Player.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/* ============================================================================================== */
/*                                             Player                                             */
/* ============================================================================================== */
Player::Player(glm::vec2 position, glm::vec2 size, float rotate, float velocity) {
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
    textSettings.imagePath = "res/image/paddle.png";
    textSettings.Format = GL_RGBA;
    textSettings.Wrap_S = GL_REPEAT;
    textSettings.Wrap_T = GL_REPEAT;
    textSettings.Filter_Min = GL_LINEAR_MIPMAP_LINEAR;
    textSettings.Filter_Max = GL_LINEAR;


    playerObj = GameObject( "res/shaders/vert.glsl",
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
void Player::onUpdate() {

    if(playerObj.Position.x <= 0.128f){ //Screen_width.x + playerObj.Size.x
        playerObj.Position.x = 0.0f;
    }
    if(playerObj.Position.x >= 672.0f){ //Screen_width.x - playerObj.Size.x
        playerObj.Position.x = 672.0f;
    }
}

/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void Player::onRenderer(glm::mat4 projection){

    this->onUpdate();

    playerObj.onRenderer(projection);
}

/* ============================================================================================== */
/*                                             onInput                                            */
/* ============================================================================================== */
void Player::onInput(bool Keys[], float dt) {


    float velocity = Velocity * dt;

    if(Keys[GLFW_KEY_LEFT]){
        playerObj.Position.x -= velocity;
        
    }

    if(Keys[GLFW_KEY_RIGHT]){
        playerObj.Position.x += velocity;
       
    }
}


/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Player::onDestroy() {

    playerObj.onDestroy();

}