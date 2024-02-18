#include "pro.h"

void jverti(char * fichier, imagex* im4) {
	int i, j;
	FILE* f = NULL;
	FILE* f2 = NULL;
	f2 = fopen("images/images_output/jverti.txt", "w"); // creation nouveau fichier texte pour y ecrire la nouvelle photo obtenue
	imagex * im;
	im4 = mhori("images/images_input/image1.txt");
	im = Lecture(f, fichier);
	fprintf(f2, "P%c\n", im->magn); // ecriture de l'entête dans le fichier
	fprintf(f2, "%d %d\n", im->larg, 2 * (im->haut)); // ecriture de la largeur de l'image et de la hauteur
	fprintf(f2, "%d\n", im->valm); // ecriture de la valeur maximale

	for (i = 0; i < im->haut; i++) {
		for (j = 0; j < im->larg; j++) {
			fprintf(f2, "%d ", (im4->donnee[i][j]).r);
			fprintf(f2, "%d ", (im4->donnee[i][j]).v); // utilisation de im4 qui vient de la fonction mhori
			fprintf(f2, "%d ", (im4->donnee[i][j]).b);
		}

		fprintf(f2, "\n");
	}

	for (i = 0; i < im->haut; i++) {
		for (j = 0; j < im->larg; j++) {
			fprintf(f2, "%d ", (im->donnee[i][j]).r);
			fprintf(f2, "%d ", (im->donnee[i][j]).v); // boucles pour ecrire les donnee correpondantes aux valeurs des couleurs rouge, vert, bleu
			fprintf(f2, "%d ", (im->donnee[i][j]).b);
		}

		fprintf(f2, "\n");
	}

	fclose(f2);
	freeim(im); // liberer memoire prise par im
	freeim(im4); // liberer memoire prise par im4

	return;
}
