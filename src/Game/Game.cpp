#include "Game.hpp"
#include "../Core/Graphics/Shader.hpp"
#include "../Core/Utils/Time.hpp"
#include <iostream>


//Projection
glm::mat4 projection = glm::mat4(1.0f);


#include "Snake.hpp"
Snake snake;

/* ============================================================================================== */
/*                                             onInit                                             */
/* ============================================================================================== */
void Game::onInit(unsigned int screen_width, unsigned int screen_height) {

    //Set Projection
    projection = glm::ortho(0.0f,(float)screen_width, (float)screen_height, 0.0f, -1.0f, 1.0f);


    snake = Snake(  glm::vec2(0.0f, 0.0f),          //Position
                    glm::vec2(16.0f, 16.0f),        //Size
                    0.0f,                           //Rotation
                    100.0f,                         //Velocity
                    glm::vec3(0.5f, 1.0f, 1.0f)     //Color)
                );
}

/* ============================================================================================== */
/*                                            onUpdate                                            */
/* ============================================================================================== */
void Game::onUpdate(){

    
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
    this->onUpdate();

    //Snake Renderer
    snake.onRenderer(projection);

       
}


/* ============================================================================================== */
/*                                             onInput                                            */
/* ============================================================================================== */
void Game::onInput(float dt){
    
    snake.onInput(Keys, dt);

}



/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Game::onDestroy() {

    snake.onDestroy();

    
}
