#include <GL/gl.h>
#include "texture.h"
#include <stb_image.h>
#include <entity.h>

    void Entity::init(int x, int y)
    {

    }

    void Entity::update(bool *controller)
    {

    }

    void Entity::draw()
    {
        tex.bind();
        glBegin(GL_QUADS);
        glVertex2i(dem.x+dem.w,dem.y+dem.h);
        glTexCoord2i(0, 0);
        glVertex2i(dem.x,dem.y+dem.h);
        glTexCoord2i(0, 1);
        glVertex2i(dem.x,dem.y);
        glTexCoord2i(1, 1);
        glVertex2i(dem.x+dem.w,dem.y);
        glTexCoord2i(1, 0);
        glEnd();
        tex.unbind();

        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex2i(dem.x,dem.y);
        glEnd();

    }

    void Entity::setTexture(char const* name, int width, int height)
    {
        tex.init(name, width, height);
    }

    void Entity::setXY(int x, int y)
    {
        dem.x = x;
        dem.y = y;
    }

    int Entity::getX()
    {
        return dem.x;
    }

    int Entity::getY()
    {
        return dem.y;
    }

    void Entity::setWidthHeight(int w, int h)
    {
        dem.w = w;
        dem.h = h;
    }

    int Entity::getWidth()
    {
        return dem.w;
    }

    int Entity::getHeight()
    {
        return dem.h;
    }

    bool Entity::testCollision(Demension oDem)
    {
        int myXCentre = dem.w/2;
        int myYCentre = dem.h/2;
        int myXOrigin = dem.x+myXCentre;
        int myYOrigin = dem.y+myYCentre;

        int oXCentre = oDem.w/2;
        int oYCentre = oDem.h/2;
        int oXOrigin = oDem.x+oXCentre;
        int oYOrigin = oDem.y+oYCentre;

        if (abs(myXOrigin - oXOrigin) > myXCentre) return false;
        if (abs(myXOrigin - oXOrigin) > oXCentre) return false;
        if (abs(myYOrigin - oYOrigin) > myYCentre) return false;
        if (abs(myYOrigin - oYOrigin) > oYCentre) return false;

        return true;
    }
