#ifndef BASEOBJ_H_INCLUDED
#define BASEOBJ_H_INCLUDED
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"Painter.h"
#include"SDL_utils.h"
#include<time.h>
#include"stdlib.h"
#include<vector>
using namespace std;

class baseObj
{
public:
    baseObj();
    ~baseObj();
    void setPosition( float a1 );
    void setRect( SDL_Rect rect_ );
    void setTexture( SDL_Renderer *renderer, string nameTexture );
    void show( SDL_Renderer *renderer );

    SDL_Texture *objTexture;
    SDL_Rect rect;
};

bool isBoom( SDL_Rect rect1, SDL_Rect rect2 );

#endif // BASEOBJ_H_INCLUDED
