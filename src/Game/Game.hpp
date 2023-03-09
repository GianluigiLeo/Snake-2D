#ifndef __GAME_HPP__
#define __GAME_HPP__


#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Game {

    public:
        bool Keys[1024];

    public:
        void onInit(unsigned int screen_width, unsigned int screen_height);
        void onUpdate();
        void onRenderer();
        void onInput(float dt);
        void onDestroy();

    private:
};
#endif // __GAME_HPP__