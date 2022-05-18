#include"tankBulletObject.h"
#include"tankObject.h"

    bulletObject::bulletObject()
    {
        this->rect.y = TANKOBJECT_BEGIN_Y;
        isMove = false;
        bulletType = 0;
    }
    bulletObject::~bulletObject()
    {
        ;
    }
    void bulletObject::handleMove()
    {
        this->rect.y -= 20;
        if( this->rect.y < 0 )
        {
            isMove = false;
        }
    }

    void bulletObject::planeMove()
    {
        srand(time(NULL));
        int up = rand()%30;
        if( this->rect.y + up <= SCREEN_HEIGHT - 400) this->rect.y += up;
        srand(time(0));
        int down = rand()%15;
        if( this->rect.y - down >= 0 )this->rect.y -= down;
        srand(time(0));
        this->rect.x += rand()%20;
        //(rand()%70+30) ;
        if( rect.x > SCREEN_WIDTH ) isMove = false;
    }
