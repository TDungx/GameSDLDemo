#ifndef SDL_UTILS_H_INCLUDED
#define SDL_UTILS_H_INCLUDED

#include<iostream>
#include<SDL.h>
#include<math.h>
#include<SDL_image.h>
#include"Painter.h"

using namespace std;

static SDL_Window *window ;
static SDL_Renderer *renderer;


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

#endif // SDL_UTILS_H_INCLUDED
