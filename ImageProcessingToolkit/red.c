#include "pro.h"

void red(char *fichier, char *fichier1) {
	int i, j;
	int l, h;
	printf("entrer largeur (nombre divisible par 8 sans reste (ex 200)) et hauteur:\n");
	scanf("%d", &l); // nouvelle largeur et hauteur de l'image
	scanf("%d", &h);
	images *im;
	images *im1;
	FILE *f = NULL;
	FILE *f1 = NULL;
	FILE *f2 = NULL;
	FILE *f3 = NULL;
	f2 = fopen("images/images_output/red1.txt", "w");
	im = Lecturepgm(f, fichier); // lecture de la premiere image
	fprintf(f2, "P%c\n", im->magn); // ecriture des differents parametres dans le nouveau fichier
	fprintf(f2, "%d %d\n", l, h);
	fprintf(f2, "%d\n", im->valm);

	for (i = 0; i < h; i++) {
		for (j = 0; j < l; j++) {
			fprintf(f2, "%d ", (im->donnee[i][j])); // ecriture de la nouvelle image redimensionnee
		}

		fprintf(f2, "\n");
	}

	fclose(f2);

	f3 = fopen("images/images_output/red2.txt", "w");
	im1 = Lecturepgm(f1, fichier1); // lecture de la deuxieme image
	fprintf(f3, "P%c\n", im1->magn); // ecriture des differents parametres dans le nouveau fichier
	fprintf(f3, "%d %d\n", l / 8, h);
	fprintf(f3, "%d\n", im1->valm);

	for (i = 0; i < h; i++) {
		for (j = 0; j < l / 8; j++) {
			fprintf(f3, "%d ", (im1->donnee[i][j])); // ecriture de la nouvelle image redimensionnee
		}

		fprintf(f3, "\n");
	}

	fclose(f3);

	return;
}
