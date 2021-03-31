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

    //GLuint tex;
    Texture tex;

    public:
    void init(int xx, int yy)
    {
        x = xx;
        y = yy;
        width = 16;
        height = 32;
        xOrigin = 8;
        yOrigin = 16;

        tex.init("textures/bearsmall.png", 64, 64);
    }

    void update(bool controller[])
    {
        /*int xd = (int)controller[1] + -1*(int)controller[3];
        x += xd;
        int yd = (int)controller[0] + -1*(int)controller[2];
        y += yd;*/
    }

    void draw()
    {
        //glColor3f(1,0,0);
        tex.bind();
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

        tex.unbind();

        //glColor3f(1,1,1);
    }

    void setXY(int xx, int yy)
    {
        x = xx;
        y = yy;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    void setWidthHeight(int w, int h)
    {
        width = w;
        height = h;
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    void setOrigin(int xx, int yy)
    {
        xOrigin = xx;
        yOrigin = yy;
    }

};
