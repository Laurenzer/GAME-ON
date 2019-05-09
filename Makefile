prog:main00.o fonction.o 
	gcc main00.o fonction.o -o prog -lSDL -lSDL_image
main00.o:main00.c
	gcc -c main00.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
