#define STB_IMAGE_IMPLEMENTATION
#include <STB_IMAGE/stb_image.h>
#include "Texture.hpp"
#include <GL/glew.h>
#include <iostream>


/* ============================================================================================== */
/*                                              Load                                              */
/* ============================================================================================== */
void Texture::Load(TextureSettings& textureSettings){


    glGenTextures(1, &m_ID);
    glBindTexture(GL_TEXTURE_2D, m_ID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureSettings.Wrap_S);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureSettings.Wrap_T);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureSettings.Filter_Min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureSettings.Filter_Max);

    stbi_set_flip_vertically_on_load(true);

    int data_width, data_height, nrChannels;
    unsigned char *data = stbi_load(textureSettings.imagePath, &data_width, &data_height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, textureSettings.Format, data_width, data_height, 0, textureSettings.Format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0); //Unbind



}


/* ============================================================================================== */
/*                                              Bind                                              */
/* ============================================================================================== */
void Texture::Bind(){

    glBindTexture(GL_TEXTURE_2D, m_ID);
}