#ifndef DEF_FCT
#define DEF_FCT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);
char lireCaractere();
int gagne(int lettreTrouvee[], long tailleMot);
int rechercheLettre(char lettre, char motSecret[],int nombre);
int verifier_reponse(char *m1,char *m2,int nombre);



#endif

