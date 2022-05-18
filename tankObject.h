#ifndef TANKOBJECT_H_INCLUDED
#define TANKOBJECT_H_INCLUDED

#define TANKOBJECT_HEIGHT 150
#define TANKOBJECT_WIDTH 180
#define TANKOBJECT_BEGIN_X 0
#define TANKOBJECT_BEGIN_Y 480

#include"SDL_utils.h"
#include"baseObj.h"
#include"tankBulletObject.h"
#include<vector>



using namespace std;

class tankObject : public baseObj
{
public:
    tankObject();
    ~tankObject();
    void handleMove();
    void inputAction( SDL_Event event );
private:

};


#endif // TANKOBJECT_H_INCLUDED
/*
if( g_event.type == SDL_MOUSEBUTTONDOWN )
            {
                bulletObject p_amo;
                if( g_event.button.button == SDL_BUTTON_LEFT )
                {
                    p_amo.rect.x = tankObj.rect.x + TANKOBJECT_WIDTH/2 - BULLETOBJECT_WIDTH/2;
                    p_amo.rect.y = TANKOBJECT_BEGIN_Y;
                    p_amo.rect.w = BULLETOBJECT_WIDTH;
                    p_amo.rect.h = BULLETOBJECT_HEIGHT;
                    p_amo.setTexture(renderer, "bullet.png");
                }
                else
                {
                    p_amo.rect.x = tankObj.rect.x + TANKOBJECT_WIDTH/2 - BULLETOBJECT_WIDTH/2;
                    p_amo.rect.y = TANKOBJECT_BEGIN_Y;
                    p_amo.rect.w = LASEROBJECT_WIDTH;
                    p_amo.rect.h = LASEROBJECT_HEIGHT;
                    p_amo.setTexture(renderer, "laser.png");
                }
                bulletList.push_back(p_amo);

            }
*/
