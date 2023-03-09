#include "Blocks.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/* ============================================================================================== */
/*                                             Player                                             */
/* ============================================================================================== */
Blocks::Blocks(glm::vec2 position, glm::vec2 size, float rotate, Blocks_Colors& blocksColor) {
    Position = position;
    Size = size;
    Rotate = rotate;
    Velocity = 0.0f;
    Color = glm::vec3(1.0, 1.0, 1.0);

    VertexBuffers vertexBuff;
    vertexBuff.VertexPosition = {
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };
    vertexBuff.VertexTexture = {
        0.0, 0.0,
        1.0, 1.0,
        0.0, 1.0,

        0.0, 0.0,
        1.0, 0.0,
        1.0, 1.0
    };

    TextureSettings textSettings;
    textSettings.imagePath = "res/image/blocks.png";
    textSettings.Format = GL_RGBA;
    textSettings.Wrap_S = GL_REPEAT;
    textSettings.Wrap_T = GL_REPEAT;
    textSettings.Filter_Min = GL_LINEAR_MIPMAP_LINEAR;
    textSettings.Filter_Max = GL_LINEAR;


    blocksObj = GameObject( "res/shaders/blocksVert.glsl",
                            "res/shaders/blocksFrag.glsl",
                            vertexBuff,
                            textSettings,
                            Position,
                            Size,
                            Rotate,
                            Velocity,
                            Color
                            );

    // blocksObj.GetShader().Use();
    // blocksObj.GetShader().setFloat("uv_x", 0.0); //0.50
    // blocksObj.GetShader().setFloat("uv_y", 0.0); //0.50
    // blocksObj.GetShader().setFloat("nx_frame", 8); //0.50
    // blocksObj.GetShader().setFloat("ny_frame", 1); //0.50
    
    setColor(blocksColor);
}



/* ============================================================================================== */
/*                                            onUpdate                                            */
/* ============================================================================================== */
void Blocks::onUpdate() {
    
}

/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void Blocks::onRenderer(glm::mat4 projection){

    this->onUpdate();

    blocksObj.onRenderer(projection);
}




/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Blocks::onDestroy() {

    blocksObj.onDestroy();

}




/* ============================================================================================== */
/*                                            setColor                                            */
/* ============================================================================================== */
void Blocks::setColor(Blocks_Colors& blocksColor) {
    
    blocksObj.GetShader().Use();
    blocksObj.GetShader().setFloat("uv_x", blocksColor); //0.50
    blocksObj.GetShader().setFloat("uv_y", 0.0); //0.50
    blocksObj.GetShader().setFloat("nx_frame", 8); //0.50
    blocksObj.GetShader().setFloat("ny_frame", 1); //0.50
    
}





