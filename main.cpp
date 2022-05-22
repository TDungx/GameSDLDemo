#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"SDL_utils.h"
#include"Painter.h"
#include"baseObj.h"
#include"tankObject.h"
#include<vector>
#include<SDL_mixer.h>

using namespace std;

SDL_Surface* g_screen = NULL;
SDL_Surface* g_background = NULL;
SDL_Event g_event;

static Painter painter(window , renderer) ;


int numLife = 3;
const int SCREEN_BPP = 64;

#define PLANEHEIGHT 80
#define PLANEWIDTH 100
#define BOOMHEIGHT 30
#define BOOMWIDTH 30


int main(int argc , char* argv[])
{
    string arr[10] = {
    "0.png" , "1.png" , "2.png" , "3.png" , "4.png" , "5.png" , "6.png" , "7.png" , "8.png" , "9.png"
    };
//int x;
    int result = 0;
    SDL_Window *window ;
    SDL_Renderer *renderer;
    initSDL(window, renderer);
    vector<baseObj> hearts;
    baseObj n;
    n.setTexture( renderer , "heart.png");
    n.rect.h = 100;
    n.rect.w = 100;
    n.rect.x = 0;
    n.rect.y = 0;
    hearts.push_back(n);
    n.rect.x = 100;
    n.rect.y = 0;
    hearts.push_back(n);
    n.rect.x = 200;
    n.rect.y = 0;
    hearts.push_back(n);
    SDL_Texture* BgTexture = NULL;
    BgTexture = loadTexture(renderer , "BGImg.png");
    createImage(renderer, BgTexture);
    tankObject tankObj;
    tankObj.setTexture(renderer, "tankObject.png");
    bool isContinue = true;
    vector<bulletObject> bulletList;
    vector<bulletObject> plane;
    vector<bulletObject> bum;
    vector<bulletObject> boom;
    while( isContinue == true )
    {
        int haha = rand();
        cout << haha << " ";
        if( haha % 30 == 0 )
        {

            bulletObject planei;
            planei.isMove = true;
            planei.rect.w = PLANEWIDTH;
            planei.rect.h = PLANEHEIGHT;
            planei.rect.y = rand() % 300;
            planei.rect.x = 0;
            planei.setTexture(renderer, "plane2.png");
            plane.push_back(planei);
        }
        while( SDL_PollEvent(&g_event) )
        {
            if( g_event.type == SDL_QUIT  )
            {
                isContinue = false;
                break;
            }

            tankObj.inputAction( g_event );
            if( g_event.type == SDL_MOUSEBUTTONDOWN )
            {

                bulletObject p_amo;
                bulletObject boomi;
                if( g_event.button.button == SDL_BUTTON_LEFT )
                {
                    p_amo.rect.x = tankObj.rect.x + TANKOBJECT_WIDTH/2 - BULLETOBJECT_WIDTH/2;
                    p_amo.rect.y = TANKOBJECT_BEGIN_Y;
                    p_amo.rect.w = BULLETOBJECT_WIDTH;
                    p_amo.rect.h = BULLETOBJECT_HEIGHT;
                    p_amo.setTexture(renderer, "bullet.png");
                    p_amo.isMove = true;
                }
                else
                {
                    p_amo.rect.x = tankObj.rect.x + TANKOBJECT_WIDTH/2 - BULLETOBJECT_WIDTH/2;
                    p_amo.rect.y = TANKOBJECT_BEGIN_Y;
                    p_amo.rect.w = LASEROBJECT_WIDTH;
                    p_amo.rect.h = LASEROBJECT_HEIGHT;
                    p_amo.setTexture(renderer, "laser.png");
                    p_amo.isMove = true;
                }
                if( plane.size() > 0 )
                {
                    boomi.rect.x = plane[0].rect.x;
                    boomi.rect.y = plane[0].rect.y;
                    boomi.rect.h = BOOMHEIGHT;
                    boomi.rect.w = BOOMWIDTH;
                    boomi.setTexture( renderer , "boomi.png");
                    boomi.isMove = true;
                    boom.push_back(boomi);
                }
                bulletList.push_back(p_amo);
                break;
            }
        }

        BgTexture = loadTexture(renderer , "BGImg.png");
        createImage(renderer, BgTexture);

        for( int i = 0 ; i < bulletList.size() ; i++ )
        {
            if( bulletList[i].isMove == true )
            {
                bulletList[i].handleMove();
            }
            else bulletList.erase(bulletList.begin()+i);
            bulletList[i].show(renderer);

        }

        for( int i = 0 ; i < boom.size() ; i++ )
        {
            if( boom[i].rect.x >= SCREEN_HEIGHT ) boom[i].isMove = false;
            if( isBoom( tankObj.rect , boom[i].rect )) boom[i].isMove = false,numLife --;
            if( boom[i].isMove == true )
            {
                boom[i].rect.y += 5;
            }
            else boom.erase(boom.begin()+i);
            boom[i].show(renderer);

        }


            for( int i = 0 ; i < plane.size() ; i++ )
        {
            if(plane[i].rect.x >= SCREEN_WIDTH )
            {
                plane.erase( plane.begin() + i );
                i--;
                numLife-- ;
                break;
            }
            plane[i].show(renderer);
            for( int j = 0 ; j < bulletList.size() ; j++ )
            {
                if( isBoom( bulletList[j].rect , plane[i].rect ) )
                {
                    bulletObject bumi;
                    bumi.rect = plane[i].rect;
                    bumi.setTexture(renderer , "bum1.png");
                    bumi.bulletType = 1;
                    bum.push_back(bumi);
                    plane.erase( plane.begin() + i );
                    bulletList.erase( bulletList.begin() + j );
                    result++;
                }
            }
            if( plane[i].isMove == true ) plane[i].planeMove();
            else plane.erase(plane.begin() + i);

        }

        for( int i = 0 ; i < bum.size() ; i++ )
        {
            if( bum[i].bulletType < 11 ) bum[i].bulletType++,bum[i].show(renderer);
            else bum.erase( bum.begin() + i );

        }
        for( int i = 0 ; i < numLife ; i++ )
        {
            hearts[i].show(renderer);
        }
        if( numLife <= 0 ) isContinue = false;
        tankObj.show( renderer );
        SDL_RenderPresent(renderer);
        SDL_DestroyTexture(BgTexture);

    }
    cout << result << endl;
    int numNum = 0;
    vector<baseObj> RESULT ;
    if( result == 0 )
    {
        baseObj tmp;
        tmp.rect.h = 200;
        tmp.rect.w = 200;
        tmp.rect.y = 400;
        tmp.setTexture( renderer , arr[0] );
        RESULT.push_back(tmp);
        numNum++;
    }

    while( result != 0 )
    {
        baseObj tmp;
        tmp.rect.h = 200;
        tmp.rect.w = 200;
        tmp.rect.y = 400;
        tmp.setTexture( renderer , arr[result % 10] );
        RESULT.push_back(tmp);
        result = result/10;
        numNum++;
    }
    BgTexture = loadTexture(renderer, "result.jpg");
    createImage(renderer, BgTexture);
    for( int i = 0 ; i < numNum ; i++ )
    {
        RESULT[i].rect.x = 700 + ( numNum/2.0 )* 200 - 200*i;
        RESULT[i].show(renderer);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
    waitUntilKeyPressed();
    SDL_Quit();
    return 0;
}
