#include <GL/gl.h>
#include "texture.h"
#include <stb_image.h>
#include <entity.h>

    void Entity::init(int xx, int yy)
    {

    }

    void Entity::update(bool *controller)
    {

    }

    void Entity::draw()
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

    void Entity::setTexture(char const* name, int width, int height)
    {
        tex.init(name, width, height);
    }

    void Entity::setXY(int xx, int yy)
    {
        x = xx;
        y = yy;
    }

    int Entity::getX()
    {
        return x;
    }

    int Entity::getY()
    {
        return y;
    }

    void Entity::setWidthHeight(int w, int h)
    {
        width = w;
        height = h;
    }

    int Entity::getWidth()
    {
        return width;
    }

    int Entity::getHeight()
    {
        return height;
    }

    void Entity::setOrigin(int xx, int yy)
    {
        xOrigin = xx;
        yOrigin = yy;
    }
