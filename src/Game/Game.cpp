#include "Game.hpp"
#include "../Core/Graphics/Shader.hpp"
#include "../Core/Entity/GameObject.hpp"
#include "../Core/Physic/Physic.hpp"
#include "../Core/Utils/Time.hpp"
#include <iostream>

//Projection
glm::mat4 projection = glm::mat4(1.0f);

//Physic
Physic physicObj;

//Background
#include "Background.hpp"
Background background;

//Player - Paddle
#include "Player.hpp"
Player paddle;

//Enemys - Blocks
#include "Blocks.hpp"
Blocks blocks[100];

//Ball
#include "Ball.hpp"
Ball ball;



/* ============================================================================================== */
/*                                             onInit                                             */
/* ============================================================================================== */
void Game::onInit(unsigned int screen_width, unsigned int screen_height) {


    //Set Projection
    projection = glm::ortho(0.0f,(float)screen_width, (float)screen_height, 0.0f, -1.0f, 1.0f);


    //Background
    background = Background(glm::vec2(0.0f, 0.0f),      //Position
                            glm::vec2(800.0f, 600.0f),  //Size
                            0.0f                        //Rotation
                            );
    //Player - Paddle
    paddle = Player(glm::vec2(400 - 64, 550.0f),    //Position
                    glm::vec2(128.0f, 18.0f),       //Size
                    0.0f,                           //Rotation
                    300.0f                          //Velocity
                    );

    //Enemy - Blocks
    // Cyan = 0,
    // Purple,
    // Blue,
    // Green,
    // Red,
    // Yellow,
    // Violet,
    // Orange
    Blocks_Colors blockColor; //Oggetto Colore
    
    blocks[0] = Blocks(glm::vec2(400, 0.0f),            //Position
                    glm::vec2(64.0f, 32.0f),            //Size
                    0.0f,                               //Rotation
                    blockColor = Red                    //Block Color
                    );
    blocks[1] = Blocks(glm::vec2(200, 0.0f),            //Position
                    glm::vec2(64.0f, 32.0f),            //Size
                    0.0f,                               //Rotation
                    blockColor = Cyan                   //Block Color
                    );


    //Ball
    ball = Ball(glm::vec2(200.0, 150.0f),       //Position
                glm::vec2(16.0f, 16.0f),        //Size
                0.0f,                           //Rotation
                150.0f                          //Velocity
                );

}

/* ============================================================================================== */
/*                                            onUpdate                                            */
/* ============================================================================================== */
void Game::onUpdate(float dt){

    float test_speed = 10.0f;

    //Divisione paddle
    //Collision ball <--> paddle
    if(physicObj.onCollision(ball.GetGameObject(), paddle.GetGameObject())){
        std::cout << "Collisione" << std::endl;
        // ball.GetGameObject().Position -=  ball.Velocity * dt;
        ball.onMove(dt);
        
    }
    // if(physicObj.onCollision(ball.GetGameObject(), paddle.GetGameObject())){
    //     ball.onMove(dt);
    // }
    

}

/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void Game::onRenderer() {

    //Colore Background
    glClearColor(0.0f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //DeltaTime
    float dt = Time::DeltaTime();

    //Inputs Game
    this->onInput(dt);

    //Update Game
    this->onUpdate(dt);

    //Background Renderer
    background.onRenderer(projection);

    //Paddle Renderer
    paddle.onRenderer(projection);

    //Blocks Renderer
    blocks[0].onRenderer(projection);
    blocks[1].onRenderer(projection);

    //Ball
    ball.onRenderer(projection);
 
       
}


/* ============================================================================================== */
/*                                             onInput                                            */
/* ============================================================================================== */
void Game::onInput(float dt){
    
    paddle.onInput(Keys, dt);
    ball.onInput(Keys, dt);

}




/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Game::onDestroy() {

    background.onDestroy();
    paddle.onDestroy();
    blocks[0].onDestroy();
    blocks[1].onDestroy();
    ball.onDestroy();
    
}
