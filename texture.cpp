#include <GL/gl.h>
#include <stb_image.h>
#include <texture.h>

    void Texture::init(char const* name, int width, int height)
    {
        int m_Width = width;
        int m_Height = height;
        int m_BPP = 4;
        unsigned char*  m_LocalBuffer = stbi_load(name, &m_Width, &m_Height, &m_BPP, 4);

        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Texture::bind()
    {
        glBindTexture(GL_TEXTURE_2D, tex);
        glEnable(GL_TEXTURE_2D);
    }

    void Texture::unbind()
    {
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
