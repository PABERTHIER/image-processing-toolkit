#include "pro.h"

void mverti(char *fichier) {
	int i, j;
	FILE *f = NULL;
	FILE *f1 = NULL;
	f1 = fopen("images/images_output/mverti.txt", "w"); // creation nouveau fichier texte pour y ecrire la nouvelle photo obtenue
	imagex *im;
	im = Lecture(f, fichier);
	fprintf(f1, "P%c\n", im->magn); // ecriture de l'entête dans le fichier
	fprintf(f1, "%d %d\n", im->larg, im->haut); // ecriture de la largeur de l'image et de la hauteur
	fprintf(f1, "%d\n", im->valm); // ecriture de la valeur maximale

	for (i = (im->haut) - 1; i > -1; i--) {
		for (j = 0; j < im->larg; j++) {
			fprintf(f1, "%d ", (im->donnee[i][j]).r);
			fprintf(f1, "%d ", (im->donnee[i][j]).v); // boucle pour ecrire les donnee correpondantes aux valeurs des couleurs rouge, vert, bleu
			fprintf(f1, "%d ", (im->donnee[i][j]).b);
		}

		fprintf(f1, "\n");
	}

	fclose(f1);
	freeim(im); // liberer memoire prise par im

	return;
}
