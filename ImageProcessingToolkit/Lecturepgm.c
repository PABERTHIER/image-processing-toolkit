#include "pro.h"

images *Lecturepgm(FILE *nom_fichier, char *fichier) { // fonction de lecture, d’un fichier image de format PGM
	int i, j;
	images *nimages; // initialisation variables
	char a[5]; // variable entete
	int b, c, d; // variables, larg,haut,valm
	int valp; // variable donnee
	nom_fichier = fopen(fichier, "r"); // ouverture fichier en mode lecture seule

	if (nom_fichier != NULL) {
		rewind(nom_fichier); // commencer au tout debut du fichier(au cas ou)
		fscanf(nom_fichier, "%s", a); // magn
		fscanf(nom_fichier, "%d %d", &b, &c); // larg et haut
		fscanf(nom_fichier, "%d", &d); // valm
		nimages = memoirepgm(b, c); // allocation memoire a nimages la variable de type images*
		nimages->magn = a[1];
		nimages->valm = d;

		for (i = 0; i < c; i++) {
			for (j = 0; j < b; j++) {
				fscanf(nom_fichier, "%d", &valp); // donnee
				nimages->donnee[i][j] = valp;
			}
		}

		fclose(nom_fichier); // fermeture du fichier

		return nimages; // on retourne notre variable nimages obtenue
	}
}
