#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__


#include "../Game/Game.hpp"

class Application {


    private:
        unsigned int SCREEN_WIDTH, SCREEN_HEIGHT;
        const char* TITLE;
    
    public:
        Application(unsigned int screen_width, unsigned int screen_height, const char* title);
        void Run();

    private:
        void Init();
        void MainLoop();
        void Destroy();


    //Handle Finestra
    private:
        GLFWwindow* m_window;
    public:
        GLFWwindow* getWindowHandle() { return m_window; }


    //Callbacks
    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
        


};


#endif //__APPLICATION_HPP__