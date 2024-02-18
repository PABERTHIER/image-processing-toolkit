#include "pro.h"

void copie(char * fichier) { // copie d'une image PPM en memoire
	FILE * f; // initialisation fichier
	imagex * nimagex1; // initialisation variable de type imagex*
	nimagex1 = Lecture(f, fichier); // lecture du fichier a copier (image)
	Write(nimagex1); // ecriture dans nouveau document ce qui est en memoire(fichier lu/image)
	freeim(nimagex1); // liberation memoire 
}
