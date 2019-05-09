#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"

int main(int argc, char *argv[])
{
int a,b,continuer=0;
SDL_Surface *screen;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(640,480,32,SDL_DOUBLEBUF|SDL_HWSURFACE);
SDL_Event event;
while(continuer)
{
a=enigme();
switch(a)
{
case 0:
continuer=0;
break;
case 1:
break;
}
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN :
 switch(event.key.keysym.sym)
 {
  case SDLK_ESCAPE : 
   continuer=0;
   break;
 }
 break;
  
}

}


}
