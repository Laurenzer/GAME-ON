#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main()
{
	SDL_Surface *ecran=NULL;
	SDL_Surface *imagedefond=NULL;
	SDL_Rect positionfond;
	char pause;

	positionfond.x=0;
	positionfond.y=0;
	

	SDL_Init(SDL_INIT_VIDEO);

	ecran=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE);

	imagedefond=IMG_Load("map1.png");
	
	SDL_BlitSurface(imagedefond,NULL,ecran,&positionfond);

	SDL_Flip(ecran);

	SDL_FreeSurface(ecran);
	pause=getchar();

return 0;

}

	
