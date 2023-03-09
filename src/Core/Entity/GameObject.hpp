#ifndef __GAMEOBJECT_HPP__
#define __GAMEOBJECT_HPP__

#include "../Graphics/Shader.hpp"
#include "../Graphics/Texture.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


struct VertexBuffers {
    std::vector<float> VertexPosition;
    std::vector<float> VertexTexture;

};

class GameObject {

    public:
        glm::vec2 Position;
        glm::vec2 Size;
        float Rotate;
        float Velocity;
        glm::vec3 Color;


    public:
        GameObject() {};
        GameObject(const char* vertexShader, const char* fragmentShader, VertexBuffers& vertexBuffer, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color);
        GameObject(const char* vertexShader, const char* fragmentShader, VertexBuffers& vertexBuffers, TextureSettings& textureSettings, glm::vec2 position, glm::vec2 size, float rotate, float velocity, glm::vec3 color);

        void onRenderer(glm::mat4 projection);
        void onDestroy();

    private:
        Shader shaderObj;
        Texture textureObj;
    public:
        Shader GetShader() { return shaderObj; }
        Texture GetTexture() { return textureObj; }

    private:
        unsigned int vao, vbo[2];

};

#endif // __GAMEOBJECT_HPP__