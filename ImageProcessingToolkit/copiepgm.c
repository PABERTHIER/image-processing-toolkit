#include "pro.h"

void copiepgm(char * fichier) { // copie d'une image PGM en memoire
	FILE * f; // initialisation fichier
	images * nimages1; // initialisation variable de type images*
	nimages1 = Lecturepgm(f, fichier); // lecture du fichier a copier (image)
	Writepgm(nimages1); // ecriture dans nouveau document ce qui est en memoire(fichier lu/image)
	freeimpgm(nimages1); // liberation memoire 
}
