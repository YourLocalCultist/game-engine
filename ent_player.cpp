#include "entity.cpp"
#include "texture.h"

class EntPlayer: public Entity
{
    private:

    Texture tex;

    public:
    void init(int xx, int yy)
    {
        setXY(xx,yy);
        setWidthHeight(16, 32);
        setOrigin(8, 32);

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
        /*tex.bind();
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

        tex.unbind();*/

        //glColor3f(1,1,1);
    }
};
