#include "Application.hpp"
#include "../Core/Debug/Debugger.hpp"
#include <iostream>

Game game;

/* ============================================================================================== */
/*                                           Application                                          */
/* ============================================================================================== */
Application::Application(unsigned int screen_width, unsigned int screen_height, const char* title) : SCREEN_WIDTH(800), SCREEN_HEIGHT(600), TITLE("Snake") {

    SCREEN_WIDTH = screen_width;
    SCREEN_HEIGHT = screen_height;
    TITLE = title; 

}

/* ============================================================================================== */
/*                                               Run                                              */
/* ============================================================================================== */
void Application::Run() {

    Init();
    MainLoop();
    Destroy();
}


/* ============================================================================================== */
/*                                              Init                                              */
/* ============================================================================================== */
void Application::Init(){

    //Init GLFW
    glfwSetErrorCallback(Debugger::checkGlfwError);
    if(!glfwInit()){
        std::cout << "Errore durante l'inizializzazione di GLFW." << std::endl;
        exit(EXIT_FAILURE);
    }

    //Set versione e profilo core GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    //Create Window
    m_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE, NULL, NULL);
    if (m_window == NULL) {
        std::cout << "Errore durante la creazione della finestra." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    } 
    glfwMakeContextCurrent(m_window);

    //GLEW
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cout << "Errore durante l'inizializzazione di GLEW!" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(m_window, key_callback);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

    glfwSwapInterval(1);
    // glViewport(0, 0, Screen_Width, Screen_Height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    //Init Game

}

/* ============================================================================================== */
/*                                            MainLoop                                            */
/* ============================================================================================== */
void Application::MainLoop() {

    while(!glfwWindowShouldClose(m_window)){


        //Game Renderer
        

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

}
/* ============================================================================================== */
/*                                             Destroy                                            */
/* ============================================================================================== */
void Application::Destroy() {

    //Game Destroy
    

    glfwDestroyWindow(m_window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

}


/* ============================================================================================== */
/*                                          key_callback                                          */
/* ============================================================================================== */
void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){

    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            game.Keys[key] = true;
        else if (action == GLFW_RELEASE)
            game.Keys[key] = false;
    }
}

/* ============================================================================================== */
/*                                    framebuffer_size_callback                                   */
/* ============================================================================================== */
void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height){

    glViewport(0, 0, width, height);

}