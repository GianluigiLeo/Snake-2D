#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include "../Core/Entity/GameObject.hpp"

class Snake : public GameObject{
    
    public:
        Snake() {}
        Snake(glm::vec2 position, glm::vec2 size, float rotate, float velocity, glm::vec3 color);

        void onUpdate();
        void onRenderer(glm::mat4 projection);
        void onInput(bool Keys[], float dt);
        void onDestroy();

    private:
        GameObject gameObj;
    public:
        GameObject& GetGameObject() { return gameObj; }
};

#endif //__SNAKE_HPP__