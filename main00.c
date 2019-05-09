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



int main (int argc, char *argv[])
{ 

	background b;
	perso pe,p2;
	objet e,ob;
	SDL_Event event;
	SDL_Surface *screen=NULL;
	SDL_Rect positione1,camera;
	int continuer = 1,frame=0,speed=10,frame2=0,c;
 	int d=0,a,x,i=0;
	SDL_Rect positiondetective;
			positiondetective.y=0;
			positiondetective.x=0;

		initialiserps2(e,30,300);

	 	//initialisation video 
		if (SDL_Init (SDL_INIT_VIDEO) == -1)
		{
			printf ("Can't init SDL: %s\n:", SDL_GetError ());
			return EXIT_FAILURE;
		}
		screen = SDL_SetVideoMode (CAMERA_W, CAMERA_H, 32,SDL_HWSURFACE |SDL_DOUBLEBUF);

		//initialisation background 
		initBckg (&b, "ok.png");
	  init_camera(&camera);
		initialiserp2(&p2);
	  afficherp2(&p2,screen,&b,&frame2);
		showBckg (screen, &b,&camera);

		//initialisation personnage
		initialiserps1(&pe);	 
		afficherpers1(screen,&pe,&frame);
		SDL_Flip(screen);
		
		//initialisation ennemi
					
		
			
		//titre fenetre
		SDL_WM_SetCaption("THE GENESIS GAME", NULL);

		//icone fenetre
int direction= 0;
 		SDL_EnableKeyRepeat (40,20);
  /*while(collision)
	  {*/		//debut des evenements
			while (continuer)
			{/*
						collision=detection_collision(&pe,ce2);
				}*/
				frame2++;
				SDL_PollEvent (&event);
        deplacerps2(&pe,&p2,screen,&b,&frame,&frame2,&speed,&camera); 
       
				switch (event.type)
				{
					case SDL_QUIT:
						continuer = 0;//quitter le jeu
					break;
					case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
						case SDLK_UP:
						break;
						case SDLK_DOWN:
						break;
						case SDLK_LEFT://evenements avec la touche gauche
						scrollToLeft (screen,&b,&camera);
						animationg(screen,&b,&pe,&frame,&speed,&ob,&camera);
						frame++;
						direction=2;
						break;
						case SDLK_RIGHT://evenements avec la touche droite
						scrollToRight (screen,&b,&camera);
						animationd(screen,&b,&pe,&frame,&speed,&ob,&camera);
						frame++;
            direction=1;
						break;
						case SDLK_l :
						scrollToLeft (screen,&b,&camera);
						accelerationg(screen,&b,&pe,&frame,&speed,&ob,&camera);
						frame++;
						break;
						case SDLK_m :
						accelerationd(screen,&b,&pe,&frame,&speed,&ob,&camera);
						frame++;
						break;
						case SDLK_v :
						 if(frame<3)
						 {
						  d=1;
						  if(frame>=3)
						  {
							 frame=0;
						  }
						  saut(screen,&b,&pe,&frame,&ob,&camera);
						 }
						 	if(frame>2||frame<6)
						  {
						   d=0;
						   if(frame<=2||frame>=6)
						   {
								frame=3;
						   }
						   saut(screen,&b,&pe,&frame,&ob,&camera);
						  }
						  frame++;
						 break;
						}
					break;
			}	
		//e=MoveEnemy(e,positiondetective,&a);
		//e=AnimateEnemy(e,a);
		//afficherpers2(screen,e);
		SDL_Flip(screen);		
    c=collision(&pe,&p2);
        switch(c)
        {
          case 0 :
          break;
          case 1 :
          x=enigme();
          switch(x)
          {
          case 0:
          continuer=0;
          break;
          case 1 :
          for(i=0;i<5;i++)
           {
             p2.p[i]=NULL;
            }
         
          break;
          }
          break;
        }	
   SDL_Delay(40);
	}
		SDL_Flip(screen);
		SDL_FreeSurface(screen);
		SDL_FreeSurface(b.img);
		    return EXIT_SUCCESS;

}
		

