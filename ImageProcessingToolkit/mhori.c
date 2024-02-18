#include "pro.h"

imagex *mhori(char *fichier) {
	int i, j;
	FILE *f = NULL;
	FILE *f1 = NULL;
	f1 = fopen("images/images_output/mhori.txt", "w"); // creation nouveau fichier texte pour y ecrire la nouvelle photo obtenue
	imagex *im;
	imagex *im1;
	im = Lecture(f, fichier);
	fprintf(f1, "P%c\n", im->magn); // ecriture de l'entête dans le fichier
	fprintf(f1, "%d %d\n", im->larg, im->haut); // ecriture de la largeur de l'image et de la hauteur
	fprintf(f1, "%d\n", im->valm); // ecriture de la valeur maximale

	for (i = 0; i < im->haut; i++) {
		for (j = (im->larg) - 1; j > -1; j--) {
			fprintf(f1, "%d ", (im->donnee[i][j]).r); // boucle pour ecrire les donnee correpondantes aux valeurs des couleurs rouge, vert, bleu
			fprintf(f1, "%d ", (im->donnee[i][j]).v);
			fprintf(f1, "%d ", (im->donnee[i][j]).b);
		}

		fprintf(f1, "\n");
	}

	im1 = Lecture(f1, "images/images_output/mhori.txt"); // im1 stocké en memoire

	fclose(f1);
	freeim(im); // liberer memoire prise par im

	return im1;// que l'on renvoi ensuite pour l'utiliser dans les juxtapositions
}
