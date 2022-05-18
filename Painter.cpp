#include"Painter.h"

void Painter::setPosition( float x , float y )
{
    this->x = x;
    this->y = y;
}

void Painter::setAngle( float angle )
{
    this->angle = angle ;
}

void Painter::setColor( SDL_Color color )
{
    this->color = color;
}

void Painter::clearWithBgColor(SDL_Color bgColor)
{
    SDL_SetRenderDrawColor(renderer,bgColor.r,bgColor.g,bgColor.b,1);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 1);
}

void Painter::jumpForward( float length )
{
    float rad = angle/180*M_PI;
    x = x + cos(rad)*length;
    y = y - sin(rad)*length;
}

void Painter::moveForward(float length)
{
    float preX = this->x;
    float preY = this->y;
    jumpForward(length);
    SDL_RenderDrawLine(renderer,(int)preX,(int)preY,(int)x,(int)y);
}

Painter::Painter(SDL_Window* window, SDL_Renderer* renderer_): renderer(renderer_)
{
    int width, height;
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0)
    SDL_GetWindowSize(window, &width, &height);
    setPosition(width/2, height/2);
    setAngle(0);
    setColor(WHITE_COLOR);
    clearWithBgColor(BLUE_COLOR);
}

void Painter::createCircle( int radius )
{
    int centerX = getX();
    int centerY = getY();
    int dx = radius;
    int dy = 0;
    int err = 0;
    while( dx >= dy )
    {
        SDL_RenderDrawPoint(renderer, centerX+dx, centerY+dy);
        SDL_RenderDrawPoint(renderer, centerX+dx, centerY-dy);
        SDL_RenderDrawPoint(renderer, centerX-dx, centerY+dy);
        SDL_RenderDrawPoint(renderer, centerX-dx, centerY-dy);
        SDL_RenderDrawPoint(renderer, centerX+dy, centerY+dx);
        SDL_RenderDrawPoint(renderer, centerX+dy, centerY-dx);
        SDL_RenderDrawPoint(renderer, centerX-dy, centerY+dx);
        SDL_RenderDrawPoint(renderer, centerX-dy, centerY-dx);
        if( err <= 0 )
        {
            dy++;
            err = err + 2*dy + 1;
        }
        else
        {
            dx--;
            err = err - 2*dx + 1;
        }
    }
}

SDL_Texture* loadTexture( SDL_Renderer *renderer, string path )
{
    SDL_Texture * newTexture = NULL;
    SDL_Surface *loadSurface = IMG_Load( path.c_str() );
    if( loadSurface == NULL )
    {
        cout << "Unable to load image " << path << " SDL_image Error: " << IMG_GetError() << endl;
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface( renderer, loadSurface );
        if( newTexture == NULL )
        {
            cout << "Unable to create texture from " << path << " SDL Error: " << SDL_GetError() << endl;
        }
        SDL_FreeSurface( loadSurface );
    }
    return newTexture;
}

bool createImage(SDL_Renderer* renderer, SDL_Texture* texture )
{
    if( texture == NULL ) return false;
    else
    {
        SDL_RenderCopy( renderer, texture, NULL , NULL );
        return true;
    }
}


