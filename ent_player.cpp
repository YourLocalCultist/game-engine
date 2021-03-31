#include "entity.h"

class EntPlayer: public Entity
{
    private:

    public:
    void init(int x, int y)
    {
        setXY(x,y);
        setWidthHeight(8, 8);
        setTexture("textures/bearsmall.png", 64, 64);
    }

    void update(bool *controller)
    {
        int xd = (int)controller[1] + -1*(int)controller[3];
        int yd = (int)controller[0] + -1*(int)controller[2];
        setXY(getX()+xd, getY()+yd);
    }
};
