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

    Texture tex;

    public:
    void init(int xx, int yy)
    {

    }

    void update(bool *controller)
    {

    }

    void draw()
    {
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

        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex2i(xOrigin+x,yOrigin+y);
        glVertex2i(x,y);
        glEnd();

    }

    void setTexture(char const* name, int width, int height)
    {
        tex.init(name, width, height);
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
