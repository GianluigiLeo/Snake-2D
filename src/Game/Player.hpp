#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "../Core/Entity/GameObject.hpp"

class Player : public GameObject {

    public:
        Player() {}
        Player(glm::vec2 position, glm::vec2 size, float rotate, float velocity);
        void onUpdate();
        void onRenderer(glm::mat4 projection);
        void onInput(bool Keys[], float dt);
        void onDestroy();

    private:
        GameObject playerObj;
    public:
        GameObject& GetGameObject() { return playerObj; }


};
#endif // __PLAYER_HPP__