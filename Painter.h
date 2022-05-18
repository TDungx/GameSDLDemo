#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

#include"SDL_utils.h"

using namespace std;

const SDL_Color CYAN_COLOR = {0, 255, 255};
const SDL_Color BLUE_COLOR = {0, 0, 255};
const SDL_Color ORANGE_COLOR = {255, 165, 0};
const SDL_Color YELLOW_COLOR = {255, 255, 0};
const SDL_Color LIME_COLOR = {0, 255, 0};
const SDL_Color PURPLE_COLOR = {128, 0, 128};
const SDL_Color RED_COLOR = {255, 0, 0};
const SDL_Color WHITE_COLOR = {255, 255, 255};
const SDL_Color BLACK_COLOR = {0, 0, 0};
const SDL_Color GREEN_COLOR = {0, 128, 0};
const SDL_Color DEFAULT_COLOR = BLACK_COLOR;


class Painter
{
    float x,y;
    float angle;
    SDL_Color color;
    SDL_Renderer* renderer;


public:
    Painter(SDL_Window * window , SDL_Renderer * renderer);
    void setPosition( float x , float y );
    void setAngle( float angle );
    float getX() {return x;}
    float getY() {return y;}
    float getAngle() {return angle;}
    void setColor( SDL_Color color);
    SDL_Color getColor() {return color;}

    void clearWithBgColor(SDL_Color color);
    void moveForward(float length);
    void moveBackward(float length) {
        moveForward(-length );
    }
    void jumpForward( float length ) ;
    void jumpBackward( float length ) {
        jumpForward(-length);
    }
    void turnLeft( float angle )
    {
        setAngle(this->angle + angle);
    }
    void turnRight(float angle)
    {
        turnLeft(-angle);
    }
    void createCircle( int radius );
};


    SDL_Texture* loadTexture( SDL_Renderer* renderer , string path );
    bool createImage( SDL_Renderer* renderer, SDL_Texture* texture );



#endif // PAINTER_H_INCLUDED
