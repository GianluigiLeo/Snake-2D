#ifndef __BLOCKS_HPP__
#define __BLOCKS_HPP__

#include "../Core/Entity/GameObject.hpp"


enum Blocks_Colors{
           Cyan = 0,
           Purple,
           Blue,
           Green,
           Red,
           Yellow,
           Violet,
           Orange
};

class Blocks : public GameObject {

    public:
        

    public:
        Blocks() {}
        Blocks(glm::vec2 position, glm::vec2 size, float rotate, Blocks_Colors& blocksColor);
        void onUpdate();
        void onRenderer(glm::mat4 projection);
        void onDestroy();

    private:
        void setColor(Blocks_Colors& blocksColor);

    private:
        GameObject blocksObj;
    public:
        GameObject& GetGameObject() { return blocksObj; }


};

#endif // __BLOCKS_HPP__