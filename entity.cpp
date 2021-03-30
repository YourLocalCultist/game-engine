#include <GL/gl.h>

class Entity
{
    private:
    int x;
    int y;
    int width;
    int height;
    int xOrigin;
    int yOrigin;

    public:
    void init(int xx, int yy)
    {
        x = xx;
        y = yy;
        width = 16;
        height = 16;
        xOrigin = 8;
        yOrigin = 16;
    }

    void update(bool controller[])
    {
        int xd = (int)controller[0] + -1*(int)controller[1];
        x += xd;
    }

    void draw()
    {
        glColor3f(1,0,0);
        glBegin(GL_QUADS);
        glVertex2i(x+width-xOrigin,y+height-yOrigin);
        glVertex2i(x-xOrigin,y+height-yOrigin);
        glVertex2i(x-xOrigin,y-yOrigin);
        glVertex2i(x+width-xOrigin,y-yOrigin);
        glEnd();
        glColor3f(1,1,1);
    }
};
