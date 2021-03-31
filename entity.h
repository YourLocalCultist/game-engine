#include <GL/gl.h>
#include "texture.h"
#include <stb_image.h>
#include <iostream>
#include <vector>
#include <memory>
#pragma once

struct Demension
{
    int x;
    int y;
    int w;
    int h;
};


class Entity
{
    private:
    Demension dem;
    Texture tex;

    public:
    virtual void init(int x, int y);
    virtual void update(bool *controller);
    void draw();
    void setTexture(char const* name, int width, int height);
    void setXY(int xx, int yy);
    int getX();
    int getY();
    void setWidthHeight(int w, int h);
    int getWidth();
    int getHeight();
    bool testCollision(Demension);

};
