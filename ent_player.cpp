#include "entity.h"
#include "texture.h"

class EntPlayer: public Entity
{
    private:

    public:
    void init(int xx, int yy)
    {
        setXY(xx,yy);
        setWidthHeight(8, 8);
        setOrigin(4, 0);
        setTexture("textures/bearsmall.png", 64, 64);
    }

    void update(bool *controller)
    {
        int xd = (int)controller[1] + -1*(int)controller[3];
        int yd = (int)controller[0] + -1*(int)controller[2];
        setXY(getX()+xd, getY()+yd);
    }
};
