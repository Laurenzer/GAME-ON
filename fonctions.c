#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"
#include <time.h>
int piocherMot(char *motPioche)
{

    FILE* dico = NULL; 
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); 
    if (dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
    }
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots); 
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico);
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);
    return strlen(motPioche);
}
int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}



int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;
    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }
    return joueurGagne;
}
int rechercheLettre(char lettre, char motSecret[],int nombre)
{
    long i = 0;
    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ;i<nombre; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            fprintf(stderr,"%c\n",lettre);
            return i;
        }
        else{
             	fprintf(stderr,"%s et %d \n",motSecret,nombre);      
        }
       
    
}
return -1;
}

int verifier_reponse(char *m1,char *m2,int nombre){
 int i;
 
 for(i=0;i<nombre;i++){
     if(m1[i]!=m2[i]){
      return 0;   
     }
 }
 return 1;
}


char lireCaractere()
{
    char caractere = 0;
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
    // On lit les autres caractères mémorisés un à un jusqu'au \n
    while (getchar() != '\n') ;
    return caractere; // On retourne le premier caractère qu'on a lu
}
int enigme(void)
{
    SDL_Init;
    TTF_Init;
    char string1[100];
    char string2[11];
    int nombre_mot=0;
    int j;
    SDL_Surface *ecran=NULL,*positioncar[20]={NULL},*texte = NULL, *fond = NULL,*Enigm=NULL,*pp=NULL,*nn=NULL;
    SDL_Surface *message2=NULL;
    char pas[11];
    int t=0;
    SDL_Rect position,post,choix,position_msg;
    SDL_Event event;
    TTF_Font *police = NULL;
    TTF_Font *po=NULL;
    nombre_mot=piocherMot(string1);

    for(j=0;j<nombre_mot;j++)
    {
    string2[j]=string1[j];
    pas[j]='*';
    }
    string2[nombre_mot]='\0'; 
     pas[nombre_mot]='\0'; 
    SDL_Color couleurBlanche = {255, 255, 255};
   	char let='&';

    int nombre_chance=nombre_mot+3;
    char nombre = (char)nombre_chance;
    int continuer = 1;
    position.x=0;
    position.y=0;
    post.x=15;
    post.y=15;
    choix.x=30;
    choix.y=30;
    position_msg.x=10;
    position_msg.y=105;
  
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Afficher_Enigme", NULL);
     TTF_Init();
    
    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[100] = {0}; // Ce sera le mot à trouver
    int *lettreTrouvee = NULL; // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée
    long coupsRestants = 10; // Compteur de coups restants (0 = mort)
    long i = 0; // Une petite variable pour parcourir les tableaux
    long tailleMot = 0;
      fond = IMG_Load("Plan de travail 1.png");
     police = TTF_OpenFont("fente.ttf", 30);
     texte = TTF_RenderText_Blended(police, "Bienvenue dans GENESIS !", couleurBlanche);
     
     
      fond = IMG_Load("Plan de travail 1.png");
     po = TTF_OpenFont("fente.ttf", 30);
     Enigm = TTF_RenderText_Blended(po, " Quel est le mot secret\n", couleurBlanche);
     nn = TTF_RenderText_Blended(po, " Il vous reste\n", couleurBlanche);
     
      fond = IMG_Load("Plan de travail 1.png");
     po = TTF_OpenFont("fente.ttf", 30);
     pp = TTF_RenderText_Blended(po, pas, couleurBlanche);
     
     char st[255];
    sprintf(st,"il vous reste %d coups",nombre_chance);
    message2=TTF_RenderText_Blended(po,st, couleurBlanche);
     
     
     while (continuer)
    {
        while(SDL_PollEvent(&event))
   
        switch(event.type)
        {
              
    case SDL_QUIT:
        continuer = 0;
        break;
    case SDL_MOUSEBUTTONUP: /* Clic de la souris */
        break;
        case SDL_KEYDOWN:
                 
    switch(event.key.keysym.sym)
    {                      
	case SDLK_a:
	let='a';
	break;
	case SDLK_b:
	let='b';
	break;
	case SDLK_c:
	let='c';
	break;
	case SDLK_d:
	let='d';
	break;
	case SDLK_e:
	let='e';
	break;
	case SDLK_f:
	let='f';
	break;
	case SDLK_g:
	let='g';
	break;
	case SDLK_h:
	let='h';
	break;
	case SDLK_i:
	let='i';
	break;
	case SDLK_j:
	let='j';
	break;
	case SDLK_k:
	let='k';
	break;
	case SDLK_l:
	let='l';
	break;
	case SDLK_m:
	let='m';
	break;
	case SDLK_n:
	let='n';
	break;
	case SDLK_o:
	let='o';
	break;
	case SDLK_p:
	let='p';
	break;
	case SDLK_q:
	let='q';
	break;
	case SDLK_r:
	let='r';
	break;
	case SDLK_s:
	let='s';
	break;
	case SDLK_t:
	let='t';
	break;
	case SDLK_u:
	let='u';
	break;
	case SDLK_v:
	let='v';
	break;
	case SDLK_y:
	let='y';
	break;
	case SDLK_w:
	let='w';
	break;
	case SDLK_x:
	let='x';
	break;
	case SDLK_z:
	let='z';
	break;
	case SDLK_BACKSPACE:
	break;
	default:
	let='&';
	break;
        }
        
 if(nombre_chance>=0){
             if(rechercheLettre(let,string2,nombre_mot)!=-1){
          fprintf(stderr,"%c\n",let);
         for(j=0;j<nombre_mot;j++){
          
             if(string2[j]==let){
                 pas[j]=let;
             }
         }
             SDL_FreeSurface(pp);
         pp = TTF_RenderText_Blended(po, pas, couleurBlanche);
         SDL_FreeSurface(message2);
    sprintf(st,"il vous reste %d coups",nombre_chance);
    message2=TTF_RenderText_Blended(po,st, couleurBlanche);
     }
     else{
         nombre_chance--; 
         SDL_FreeSurface(message2);
    sprintf(st,"il vous reste %d coups",nombre_chance);
    message2=TTF_RenderText_Blended(po,st, couleurBlanche);
     }
 }
    break;     
        }
  
  if(verifier_reponse(pas,string2,nombre_mot)==1 && nombre_chance>0)
{
    SDL_FreeSurface(message2);
    message2=TTF_RenderText_Blended(po,"VOUS AVEZ GAGNE", couleurBlanche);
    t=1;
  }
  if(nombre_chance==0)
{
             SDL_FreeSurface(message2);
             sprintf(st,"VOUS AVEZ PERDU ! reponse : %s ",string2);
    message2=TTF_RenderText_Blended(po,st, couleurBlanche); 
              t=2;     
  }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        position.x = 0;
        position.y = 0;
        SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */
        position.x = 0;
        position.y = 0;
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */ 
        post.x = 0;
        post.y = 35;
        SDL_BlitSurface(Enigm, NULL, ecran, &post); 
        
        
        choix.x = 0;
        choix.y = 70;
        SDL_BlitSurface(pp, NULL, ecran, &choix); /* Blit du texte */
        SDL_BlitSurface(message2,NULL,ecran,&position_msg);
	SDL_Flip(ecran);
        switch(t)
        {
         case 0 :
         break;
         case 1 :
        SDL_Delay(3000);
        continuer=0;
        return 1;
        break;
  
         case 2 :
        SDL_Delay(3000);
        continuer=0;
        return 0;
        break;
        }
        
        
         
    }
    
    TTF_CloseFont(police);
    TTF_CloseFont(po);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_FreeSurface(Enigm);
    SDL_Quit;
    
        
        EXIT_SUCCESS;
    
          
        
}

