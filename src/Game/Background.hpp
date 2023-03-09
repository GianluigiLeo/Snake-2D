#ifndef __BACKGROUN_HPP__
#define __BACKGROUN_HPP__


#include "../Core/Entity/GameObject.hpp"

class Background : public GameObject {

    public:
        Background() {}
        Background(glm::vec2 position, glm::vec2 size, float rotate);
        void onRenderer(glm::mat4 projection);
        void onInput(bool Keys[], float dt, float velocity);
        void onDestroy();

    private:
        GameObject backgroundObj;
    public:
        GameObject& GetGameObject() { return backgroundObj; }


};

#endif // __BACKGROUN_HPP__