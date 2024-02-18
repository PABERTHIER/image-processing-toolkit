#include "pro.h"

imagex *Lecture(FILE *nom_fichier, char *fichier) { // fonction de lecture, d’un fichier image de format PPM
	int i, j;
	imagex *nimagex; // initialisation variables
	char a[5]; // variable entete
	int b, c, d; // variables, larg,haut,valm
	int valp; // variable donnee
	nom_fichier = fopen(fichier, "r"); // ouverture fichier en mode lecture seule

	if (nom_fichier != NULL) {
		rewind(nom_fichier); // commencer au tout debut du fichier(au cas ou)
		fscanf(nom_fichier, "%s", a); // magn
		fscanf(nom_fichier, "%d %d", &b, &c); // larg et haut
		fscanf(nom_fichier, "%d", &d); // valm
		nimagex = memoire(b, c); // allocation memoire a nimagex la varible de type imagex*
		nimagex->magn = a[1];
		nimagex->valm = d;

		for (i = 0; i < c; i++) {
			for (j = 0; j < b; j++) {
				fscanf(nom_fichier, "%d", &valp); // lecture des valeurs pour les couleurs rouge, vert, bleu
				(nimagex->donnee[i][j]).r = valp; // donnee
				fscanf(nom_fichier, "%d", &valp);
				(nimagex->donnee[i][j]).v = valp;
				fscanf(nom_fichier, "%d", &valp);
				(nimagex->donnee[i][j]).b = valp;
			}
		}

		fclose(nom_fichier); // fermeture du fichier

		return nimagex; // on retourne notre variable nimagex obtenue
	}
}
