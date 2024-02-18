#include "pro.h"
typedef char byte;

/* Ecrire la procédure qui permet de cacher les pixels de l’image message dans l’image de couverture */

void pmtoc(char *fichier, char *fichier2) {
	int i, j, k;
	char a[8] = {0};
	byte masque1[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}; // 00000001;    byte à 1
	byte masque2[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F}; // 11111110;    byte à 0
	images *im;
	images *im1;
	FILE *f = NULL;
	FILE *f1 = NULL;
	FILE *f2 = NULL;
	f1 = fopen("images/images_output/pmtoc.txt", "w"); // creation nouveau fichier texte pour y ecrire la nouvelle photo obtenue
	im = Lecturepgm(f, fichier);
	im1 = Lecturepgm(f2, fichier2);
	fprintf(f1, "P%c\n", im->magn); // ecriture de l'entête dans le fichier
	fprintf(f1, "%d %d\n", im->larg, im->haut); // ecriture de la largeur de l'image et de la hauteur
	fprintf(f1, "%d\n", im->valm); // ecriture de la valeur maximale

	for (i = 0; i < im->haut; i++) { // boucles de comparaisons entre les masques et l'image
		for (j = 0; j < im->larg; j++) { // à cacher, puis ecriture dans un nouveau fichier
			if ((im1->donnee[i][j] | masque1[0])) { // de l'image de couverture modifiee par l'image cachee
				im->donnee[i][j] = im->donnee[i][j] | masque1[0];
				fprintf(f1, "%d ", im->donnee[i][j]);
			} else {
				im->donnee[i][j] = im->donnee[i][j] & masque2[0];
				fprintf(f1, "%d ", (im->donnee[i][j]));
			}
		}

		fprintf(f1, "\n");
	}

	/* test
	for(i=0;i<im->haut;i++){
		for(j=0;j<im->larg/8;j++){
			for(k=0;k<8;k++){
				if (!(im1->donnee[i][j] & masque1[7-k]))
				{
					a[k] = im->donnee[i][j+k] & masque2[0];
				}
				else
				{
					a[k] = im->donnee[i][j+k] | masque1[0];
				}
			}

			for(k=0;k<8;k++){
				im->donnee[i][j] += a[k];
			}

			fprintf(f1,"%d ",(im->donnee[i][j]));
		}

		fprintf(f1,"\n");
	}
	*/

	fclose(f1);
	freeimpgm(im); // liberer memoire prise par les im de type images
	freeimpgm(im1);

	return;
}
