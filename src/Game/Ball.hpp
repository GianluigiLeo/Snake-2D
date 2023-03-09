#ifndef __BALL_HPP__
#define __BALL_HPP__

#include "../Core/Entity/GameObject.hpp"

class Ball : public GameObject {

    public:
        

    public:
        Ball() {}
        Ball(glm::vec2 position, glm::vec2 size, float rotate, float velocity);
        void onUpdate();
        void onRenderer(glm::mat4 projection);
        void onDestroy();
        void onMove(float dt);

        //Da cancellare
        void onInput(bool Keys[], float dt);


    private:
        GameObject ballObj;
    public:
        GameObject& GetGameObject() { return ballObj; }


};
#endif // __BALL_HPP__