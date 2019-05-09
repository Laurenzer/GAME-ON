prog:enigme.o fonctions.o
	gcc enigme.o fonctions.o -lSDL -lSDL_image -lSDL_ttf -o prog
enigme.o:enigme.c
	gcc enigme.c  -lSDL -lSDL_image -lSDL_ttf -c
fonctions.o:fonctions.c
	gcc -c fonctions.c
