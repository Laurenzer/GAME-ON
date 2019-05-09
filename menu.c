#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "fonction.h"
#include "enigme.h"
#include "f.h"

int main(int argc,char** argv)
{

	SDL_Surface *ecran=NULL,*menu=NULL,*texte=NULL;
	SDL_Rect positionMenu,positionClic,positionTxt;
	SDL_Event event;
	int continuer=1;

	TTF_Font *police=NULL;
	SDL_Color couleurnoire={0,0,0},couleurblanche={255,255,255};

	TTF_Font *policeBig=NULL;
 


	
	TTF_Init();//Police  initialisation
	police=TTF_OpenFont("CFCyborgPERSONALUSE-Regular.ttf",8);//petite police
	policeBig=TTF_OpenFont("CFCyborgPERSONALUSE-Regular.ttf",12);//grande police

	putenv("SDL_VIDEO_CENTERED=1");//centrer le fenetre
	SDL_Init(SDL_INIT_VIDEO);//initialisation de la SDL

	ecran=SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Menu",NULL);

	menu=IMG_Load("ppp.png");
	
	positionMenu.x=0;
	positionMenu.y=0;
	
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
	
	Mix_Music *music;
	music=Mix_LoadMUS("menu.mp3");
	Mix_PlayMusic(music,-1);

	

	while(continuer)
	{
		SDL_PollEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer=0;
			break;
			/*case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDL_ESCAPE:
						//...
					break;
				}
				*/
			case SDL_MOUSEBUTTONUP:
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					positionClic.x=event.button.x;
					positionClic.y=event.button.y;

					if(event.button.x > 320 && event.button.x < 350 && event.button.y > 220 && event.button.y < 500)//jouer
					{
						texte=TTF_RenderText_Blended(policeBig,"WILL YOU FOUND THE TRUTH?...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);

							jouer()
		;			}
					else if(event.button.x > 320 && event.button.x < 350 && event.button.y >285 && event.button.y < 500)//load
					{
						texte=TTF_RenderText_Blended(policeBig,"YOU ALREADY PLAYDED...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);

							//load(ecran)
					}
					else if(event.button.x > 320 && event.button.x < 350 && event.button.y > 350 && event.button.y < 500)//options
					{
						texte=TTF_RenderText_Blended(policeBig,"OUR GAME OPTIONS...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);

							//optjouer(ecran)
					}
					else if(event.button.x > 320 && event.button.x < 350 && event.button.y > 415 && event.button.y < 500)//credits
					{
						texte=TTF_RenderText_Blended(policeBig,"ALL AOUT THE GAME DEVELOPERS?...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);

							//credits(ecran)
					}
					else if(event.button.x > 320 && event.button.x < 350 && event.button.y > 480 && event.button.y < 500)//quit
					{
						//on quitte le jeu
						exit(0);
					}
				}	
			case SDL_MOUSEMOTION:
					if(event.motion.x > 320 && event.motion.x < 350 && event.motion.y > 220 && event.motion.y < 500)//jouer
					{
						texte=TTF_RenderText_Blended(policeBig,"WELCOME?...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);

							//jouer(ecran)
					}
					else if(event.motion.x > 320 && event.motion.x < 350 && event.motion.y > 285 && event.motion.y < 500)//load
					{
						texte=TTF_RenderText_Blended(policeBig,"LOAD GAME?...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);
					}
					else if(event.motion.x > 320 && event.motion.x < 350 && event.motion.y > 350 && event.motion.y < 500)//options
					{
						texte=TTF_RenderText_Blended(policeBig,"OPTIONS?...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);
					}
					else if(event.motion.x > 320 && event.motion.x < 350 && event.motion.y > 415 && event.motion.y < 500)//credits
					{
						texte=TTF_RenderText_Blended(policeBig,"CREDITS?...",couleurblanche);
						positionTxt.x=298;
						positionTxt.y=30;
						SDL_BlitSurface(texte,NULL,ecran,&positionTxt);
						SDL_Flip(ecran);
						SDL_Delay(150);
					}
					else if(event.motion.x > 320 && event.motion.x < 350 && event.motion.y > 480 && event.motion.y < 500)//quit
					{
						//on quitte le jeu
						exit(0);
					}
			break;	
					
		}
		
		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
		SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
		SDL_Flip(ecran);
	}
		Mix_FreeMusic(music);
		Mix_CloseAudio();
		SDL_FreeSurface(menu);

		TTF_CloseFont(police);
		TTF_Quit();

		SDL_FreeSurface(texte);
		SDL_Quit();

		return EXIT_SUCCESS;
}
