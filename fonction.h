#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define CAMERA_W  640
#define CAMERA_H  480
#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED



struct background
{
SDL_Rect bckg;
int etat;
SDL_Surface *img;
};
typedef struct background background;

typedef struct perso perso;
struct perso{
SDL_Surface *p[6];
SDL_Rect pp;
int x;
int y;
int r;
};

typedef struct objet objet;
struct objet{
SDL_Surface *image[5];
SDL_Surface *image1[4];
  SDL_Surface *Hit;

  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int fram;
  int direction;
};

typedef struct Enemy
{
  SDL_Surface *image[5];
SDL_Surface *image1[4];
  SDL_Surface *Hit;

  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int fram;
  int direction;

}Enemy;
struct entite
{
	int x;
	int y;
	int r;
};
typedef struct entite entite;

//fonctionsbg
void initBckg (background * b, char url[]);
void init_camera(SDL_Rect *camera);
void showBckg (SDL_Surface * screen, background *b,SDL_Rect *camera);
void scrollToLeft (SDL_Surface *screen,background * b,SDL_Rect *camera);
void scrollToRight (SDL_Surface *screen,background * b,SDL_Rect *camera);

//fonctionspers
void initialiserps1(perso *pr);
void initialiserp2(perso *pr);
int collision(perso *p1,perso *p2);
void afficherpers1(SDL_Surface *screen,perso *pr,int *frame);
void afficherp2(perso *pr,SDL_Surface *screen,background *b,int *frame);
void animationd(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera);
void animationg(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera);
void accelerationg(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera);
void accelerationd(SDL_Surface *screen,background *b,perso *pr,int *frame,int *speed,objet *ob,SDL_Rect *camera);
void deplacerps2(perso *pr1,perso *pr2,SDL_Surface *screen,background *b,int *frame,int *frame2,int *speed,SDL_Rect *camera);
void saut(SDL_Surface *screen,background *b,perso *pr,int *frame,objet *ob,SDL_Rect *camera);


int enigme(void);
void jouer (void);

#endif


