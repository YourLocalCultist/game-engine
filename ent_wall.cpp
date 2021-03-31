#include "entity.h"

class EntWall: public Entity
{
    private:

    public:
    void init(int xx, int yy)
    {
        setXY(xx,yy);
        setWidthHeight(64, 8);
        setTexture("textures/bearsmall.png", 64, 64);
    }
};
