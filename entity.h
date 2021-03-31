#include <GL/gl.h>
#include "texture.h"
#include <stb_image.h>
#pragma once

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
    void init(int xx, int yy);
    void update(bool *controller);
    void draw();
    void setTexture(char const* name, int width, int height);
    void setXY(int xx, int yy);
    int getX();
    int getY();
    void setWidthHeight(int w, int h);
    int getWidth();
    int getHeight();
    void setOrigin(int xx, int yy);

};
