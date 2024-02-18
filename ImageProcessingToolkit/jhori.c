#include "pro.h"

void jhori(char * fichier, imagex * im1) {
	int i, j;
	FILE* f = NULL;
	FILE* f2 = NULL;
	f2 = fopen("images/images_output/jhori.txt", "w"); // creation nouveau fichier texte pour y ecrire la nouvelle photo obtenue
	imagex * im;
	im = Lecture(f, fichier);
	im1 = mhori("images/images_input/image1.txt");
	fprintf(f2, "P%c\n", im->magn); // ecriture de l'entête dans le fichier
	fprintf(f2, "%d %d\n", 2 * (im->larg), im->haut); // ecriture de la largeur de l'image et de la hauteur
	fprintf(f2, "%d\n", im->valm); // ecriture de la valeur maximale
	int k;

	for (i = 0; i < im->haut; i++) {
		for (j = 0; j < im->larg; j++) { // boucles pour ecrire les donnee correpondantes aux valeurs des couleurs rouge, vert, bleu
			fprintf(f2, "%d ", (im->donnee[i][j]).r);
			fprintf(f2, "%d ", (im->donnee[i][j]).v);
			fprintf(f2, "%d ", (im->donnee[i][j]).b);
		}

		for (k = 0; k < im->larg; k++) {
			fprintf(f2, "%d ", (im1->donnee[i][k]).r);
			fprintf(f2, "%d ", (im1->donnee[i][k]).v); // utilisation de im1 qui vient de la fonction mhori
			fprintf(f2, "%d ", (im1->donnee[i][k]).b);
		}

		fprintf(f2, "\n");
	}

	fclose(f2);
	freeim(im); // liberer memoire prise par im
	freeim(im1); // liberer memoire prise par im1
	return;
}
