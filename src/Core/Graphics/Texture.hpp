#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__


struct TextureSettings {
    const char* imagePath;
    unsigned int Format;
    unsigned int Wrap_S;
    unsigned int Wrap_T;
    unsigned int Filter_Min;
    unsigned int Filter_Max;
};

class Texture {

    public:
        Texture() {}
        void Load(TextureSettings& textureSettings);
        void Bind();

    private:
        unsigned int m_ID;
};


#endif // __TEXTURE_HPP__