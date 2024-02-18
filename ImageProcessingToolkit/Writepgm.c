#include "pro.h"

void Writepgm(images *im) { // ecriture contenu image modifiee dans un fichier txt
	int i, j; // initialisation variables
	FILE *fichier = NULL;
	fichier = fopen("images/images_output/nimagepgm.txt", "w"); // ouverture du fichier en ecriture seule + creation s'il n'existe pas

	if (fichier != NULL) {
		fprintf(fichier, "P%c\n", im->magn); // ecriture de l'entête dans le fichier
		fprintf(fichier, "%d %d\n", im->larg, im->haut); // ecriture de la largeur de l'image et de la hauteur
		fprintf(fichier, "%d\n", im->valm); // ecriture de la valeur maximale

		for (i = 0; i < im->haut; i++) {
			for (j = 0; j < im->larg; j++) { // boucle pour ecrire les donnee correpondantes aux valeurs
				fprintf(fichier, "%d ", im->donnee[i][j]);
			}

			fprintf(fichier, "\n"); // espace et saut a la ligne pour donner la meme mise en forme qu'une image.txt
		}
	} else {
		printf("ecriture dans le fichier impossible");
	}
}
