#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fonction.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *surface1 = NULL, *surface2 = NULL, *background= NULL;
    SDL_Event event;
    SDL_Rect position1, position2,positionback,camera1,camera2;
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE);
   
    position1.x=0;
    position1.y=0;
    position2.x=600;
    position2.y=0;
    camera1.w=600;
    camera1.h=600;
    camera2.w=600;
    camera2.h=600;
    camera1.x=0;
    camera1.y=0;
    camera2.x=0;
    camera2.y=0;
		positionback.x = 0;
		positionback.y = 0;
		surface1 = SDL_LoadBMP("i2.bmp");
		position2.x=600;
		position2.y=0;
		background = IMG_Load("joueur1.png");
    SDL_BlitSurface(surface1, &camera1, ecran, &positionback );
    SDL_BlitSurface(surface1, &camera2, ecran, &position2 );
    SDL_BlitSurface(background, NULL, ecran,&positionback );
    SDL_Flip(ecran);

    while(continuer)
    {
        SDL_WaitEvent(&event);
 
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
        }
    }
    SDL_Quit();
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
    SDL_FreeSurface(background);
    return EXIT_SUCCESS;
}
