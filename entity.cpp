#include <GL/gl.h>
#include "texture.h"
#include <stb_image.h>

class Entity
{
    private:
    int x;
    int y;
    int width;
    int height;
    int xOrigin;
    int yOrigin;

    GLuint tex;

    public:
    void init(int xx, int yy)
    {
        x = xx;
        y = yy;
        width = 16;
        height = 16;
        xOrigin = 8;
        yOrigin = 16;

        stbi_set_flip_vertically_on_load(1);
        int m_Width = 64;
        int m_Height = 64;
        int m_BPP = 4;
        unsigned char*  m_LocalBuffer = stbi_load("textures/bear.png", &m_Width, &m_Height, &m_BPP, 4);

        /*unsigned char texDat[64];
            for (int i = 0; i < 64; ++i)
                texDat[i] = ((i + (i / 8)) % 2) * 128 + 127;*/
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void update(bool controller[])
    {
        int xd = (int)controller[0] + -1*(int)controller[1];
        x += xd;
    }

    void draw()
    {
        glBindTexture(GL_TEXTURE_2D, tex);
        glEnable(GL_TEXTURE_2D);
        //glColor3f(1,0,0);
        glBegin(GL_QUADS);

        glVertex2i(x+width-xOrigin,y+height-yOrigin);
        glTexCoord2i(0, 0);
        glVertex2i(x-xOrigin,y+height-yOrigin);
        glTexCoord2i(0, 1);
        glVertex2i(x-xOrigin,y-yOrigin);
        glTexCoord2i(1, 1);
        glVertex2i(x+width-xOrigin,y-yOrigin);
        glTexCoord2i(1, 0);
        glEnd();

        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        //glColor3f(1,1,1);
    }
};
