#include"tankObject.h"
#include<vector>



    tankObject::tankObject()
    {
        rect.x = TANKOBJECT_BEGIN_X;
        rect.y = TANKOBJECT_BEGIN_Y;
        rect.h = TANKOBJECT_HEIGHT;
        rect.w = TANKOBJECT_WIDTH;
        objTexture = NULL;
    }

    tankObject::~tankObject()
    {

    }

    void tankObject::handleMove()
    {

    }

    void tankObject::inputAction( SDL_Event event )
    {
        if( event.type == SDL_KEYDOWN )
        {
            if( event.key.keysym.sym == SDLK_RIGHT && rect.x <= SCREEN_WIDTH - 100 ) rect.x += TANKOBJECT_WIDTH/4;
            else if( event.key.keysym.sym == SDLK_LEFT && rect.x >= - 100 ) rect.x -= TANKOBJECT_WIDTH/4;
        }

    }

