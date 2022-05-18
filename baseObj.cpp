#include"baseObj.h"


    baseObj::baseObj()
    {
        rect.x = 0;
        rect.y = 0;
        rect.h = 0;
        rect.w = 0;
        objTexture = NULL;
    }
    baseObj::~baseObj()
    {

    }

    void baseObj::setPosition( float x_ )
    {
        rect.x = x_;
    }
    void baseObj::setRect( SDL_Rect rect_ )
    {
        rect = rect_;
    }
    void baseObj::setTexture( SDL_Renderer *renderer, string nameTexture )
    {

        objTexture = loadTexture( renderer , nameTexture );
    }
    void baseObj::show( SDL_Renderer *renderer )
    {
        SDL_RenderCopy(renderer, objTexture, NULL, &rect);
    }

    bool isBoom( SDL_Rect rect1, SDL_Rect rect2 )
    {
        if( rect1.x <= rect2.x + rect2.w && rect1.x + rect1.w >= rect2.x )
        {
            if( rect1.y <= rect2.y + rect2.h && rect1.y + rect1.h >= rect2.y ) return true;
            else return false;
        }
        else return false;
    }


