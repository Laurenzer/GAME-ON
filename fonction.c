#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include "fonction.h"
#include "enigme.h"
#define largeur_cam 300

void initBckg (background * b, char url[])
{
b->etat = -1;
b->img = IMG_Load (url);
b->bckg.x = 0;
b->bckg.y = 0;
b->bckg.w = b->img->w;
b->bckg.h = b->img->h;
}

void showBckg(SDL_Surface * screen, background *b,SDL_Rect *camera)
{
SDL_BlitSurface (b->img, camera, screen, &b->bckg);
SDL_Flip(screen);
}

void init_camera(SDL_Rect *camera)
{
	camera->x=0;
  camera->y=0;
  camera->w=640;
  camera->h=480;
}

void scrollToLeft (SDL_Surface *screen,background * b,SDL_Rect *camera)
{
	int speed=10;
	//if (b->bckg.x != 0){
	camera->x-=speed;
//}
	if(camera->x<0)
  {
    camera->x=0;
  }
        
}

void scrollToRight (SDL_Surface *screen,background * b,SDL_Rect *camera)
{
int speed=10;
//if (b->bckg.w - b->bckg.x != CAMERA_W){
camera->x+=speed;
//}
if(camera->x>2000-camera->w)
{
	camera->x=2000-camera->w;
}

}

void initialiserps1(perso *pr)
{
    pr->p[0]=IMG_Load("p1.png");
    pr->p[1]=IMG_Load("p2.png");
    pr->p[2]=IMG_Load("p3.png");
    pr->p[3]=IMG_Load("p4.png");
    pr->p[4]=IMG_Load("p5.png");
    pr->p[5]=IMG_Load("p6.png");

    pr->pp.x=30;
    pr->pp.y=300;
    pr->pp.w=-10;
}

void initialiserp2(perso *pr)
{
    pr->p[0]=IMG_Load("2.png");
    pr->p[1]=IMG_Load("3.png");
    pr->p[2]=IMG_Load("4.png");
    pr->p[3]=IMG_Load("5.png");
    pr->p[4]=IMG_Load("6.png");

    pr->pp.x=1500;
    pr->pp.y=360;
    pr->pp.w=20;
}

void afficherp2(perso *pr,SDL_Surface *screen,background *b,int *frame)
{
   SDL_BlitSurface(pr->p[*frame],NULL,screen,&pr->pp);
	 SDL_Flip(screen);
}

void deplacerps2(perso *pr,perso *pr2,SDL_Surface *screen,background *b,int *frame,int *frame2,int *speed,SDL_Rect *camera)
{
	if((*frame2)<=2||(*frame2)>=6)
    {
        *frame2=3;
    }
	 pr2->pp.x-=10;
	 showBckg(screen,b,camera);
   afficherpers1(screen,pr,frame);
	 SDL_BlitSurface(pr2->p[*frame2],NULL,screen,&pr2->pp);
	 SDL_Flip(screen);
}

 objet initialiserps2(objet Ennemie,int x, int y)
{
   Ennemie.image[0]=IMG_Load("rpg2.png");
  Ennemie.image[1]=IMG_Load("rpg3.png");
  Ennemie.image[2]=IMG_Load("rpg4.png");
Ennemie.image[3]=IMG_Load("rpg5.png");
  Ennemie.image1[0]=IMG_Load("2.png");
  Ennemie.image1[1]=IMG_Load("3.png");
Ennemie.image1[2]=IMG_Load("4.png");
Ennemie.image1[3]=IMG_Load("5.png");


  Ennemie.Hit=IMG_Load("rpg6.png");
   
 Ennemie.imageActuel=Ennemie.image[0];
  Ennemie.position.x=x;
  Ennemie.position.y=y;
  Ennemie.positionO=Ennemie.position;
  Ennemie.fram=0;
  Ennemie.direction=0;
  return Ennemie;
}

void afficherpers1(SDL_Surface *screen,perso *pr,int *frame)
{
    SDL_BlitSurface(pr->p[*frame],NULL,screen,&pr->pp);
    SDL_Flip(screen);
}

void afficherpers2(SDL_Surface *screen,objet Ennemie)
{
    SDL_BlitSurface(Ennemie.imageActuel,NULL,screen,&Ennemie.position);
    SDL_Flip(screen);
}


void animationd(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera)
{
	showBckg(screen,b,camera);
    if((*frame)>=2)
    {
        *frame=0;
    }
    if((pr->pp.x<550)&&(camera->x>=(2000-camera->w)))
	{
   
     pr->pp.x+=(*speed);
  }
  /*if(pr->pp.x>1940)
  {
     pr->pp.x=1940;
  }:*/
    
     SDL_Delay(10);
		afficherpers1(screen,pr,frame);
}

void animationg(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera)
{
    showBckg(screen,b,camera);
    if((*frame)<=2||(*frame)>=5)
    {
        *frame=3;
    }
    afficherpers1(screen,pr,frame);
if(camera->x<640)
{
	pr->pp.x-=(*speed);
}
  
}

void accelerationg(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera)
{
    camera->x-=3*(*speed);
    if((*frame)<=2||(*frame)>=5)
    {
        *frame=3;
    }
		if(camera->x<0)
    {
      camera->x=0;
      if(pr->pp.x>10)
        {
            pr->pp.x-=3*(*speed);
        }
    }
    showBckg(screen,b,camera);
    afficherpers1(screen,pr,frame);
    
    
    SDL_Delay(10);
}

int collision(perso *p1,perso *p2)
{
  if((p1->pp.x+p1->pp.w)<(p2->pp.x+40))
  {
    return 0;
  }else
  {
    return 1;
  }
}

void accelerationd(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera)
{
		camera->x+=3*(*speed);
    
    if((*frame)>=2)
    {
        *frame=0;
    }

if(camera->x>=(2000-camera->w))
{
	camera->x=2000-camera->w;
if(pr->pp.x<=500)
{
  pr->pp.x+=((*speed)*3);
}
}

	  showBckg(screen,b,camera);
    afficherpers1(screen,pr,frame);
    SDL_Delay(10);
}

void saut(SDL_Surface *screen,background *b,perso *pr,int *frame,objet *ob,SDL_Rect *camera)
{

    int s=pr->pp.y;
    if((*frame)<3)
    {
    pr->pp.x+=10;
    pr->pp.y = -0.04*((pr->pp.x)*(pr->pp.x))+100;
    showBckg(screen,b,camera);
    afficherpers1(screen,pr,frame);
    SDL_Delay(10);
    }else
    {
    pr->pp.x-=10;
    pr->pp.y=-0.04*((pr->pp.x)*(pr->pp.x))+100;
    showBckg(screen,b,camera);
    afficherpers1(screen,pr,frame);
    SDL_Delay(10);
    }
    if(pr->pp.y<s)
    {
        pr->pp.y=500;
    }

}

void jouer (void)
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

}
