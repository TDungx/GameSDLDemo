#ifndef TANKBULLETOBJECT_H_INCLUDED
#define TANKBULLETOBJECT_H_INCLUDED

#include"baseObj.h"

#define BULLETOBJECT_HEIGHT 30
#define BULLETOBJECT_WIDTH 10
#define LASEROBJECT_HEIGHT 30
#define LASEROBJECT_WIDTH 20

class bulletObject : public baseObj
{
public:
    bool isMove;
    int bulletType;
    bulletObject();
    ~bulletObject();
    void handleMove();
    void planeMove();
};

#endif // TANKBULLETOBJECT_H_INCLUDED
