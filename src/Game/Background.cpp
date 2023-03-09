#include "Background.hpp"
#include <GL/glew.h>

/* ============================================================================================== */
/*                                             Player                                             */
/* ============================================================================================== */
Background::Background(glm::vec2 position, glm::vec2 size, float rotate) {
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
    textSettings.imagePath = "res/image/background.png";
    textSettings.Format = GL_RGBA;
    textSettings.Wrap_S = GL_REPEAT;
    textSettings.Wrap_T = GL_REPEAT;
    textSettings.Filter_Min = GL_LINEAR_MIPMAP_LINEAR;
    textSettings.Filter_Max = GL_LINEAR;


    backgroundObj = GameObject( "res/shaders/vert.glsl",
                                "res/shaders/frag.glsl",
                                vertexBuff,
                                textSettings,
                                Position,
                                Size,
                                Rotate,
                                Velocity,
                                Color
                            );
}


/* ============================================================================================== */
/*                                           onRenderer                                           */
/* ============================================================================================== */
void Background::onRenderer(glm::mat4 projection){
    
    backgroundObj.onRenderer(projection);
}


/* ============================================================================================== */
/*                                            onDestroy                                           */
/* ============================================================================================== */
void Background::onDestroy() {

    backgroundObj.onDestroy();

}