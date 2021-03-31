#include <GL/gl.h>
#include <stb_image.h>
#pragma once

class Texture
{
    private:
    GLuint tex;

    public:
    void init(char const*, int, int);
    void bind();
    void unbind();

};
