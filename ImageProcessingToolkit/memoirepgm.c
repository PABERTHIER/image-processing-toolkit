#include "pro.h" // modulaire, en lien avec pro.h (prototypes, struct...)

images *memoirepgm(int x, int y) { // fonction qui réalise l’allocation en mémoire pour une image de format PGM
	int i; // initialisation
	images *I = (images *)malloc(sizeof(images)); // allocation de memoire a la variable de type images*
	I->larg = x; // largeur
	I->haut = y; // hauteur
	I->donnee = (int **)malloc(y * sizeof(int *)); // allocation de memoire pour les donnee de I

	int *ent = (int *)malloc(x * y * sizeof(int)); // allocation de memoire pour les attributions de nuances de gris

	for (i = 0; i < y; i++) {
		I->donnee[i] = ent + x * i; // taille de la matrice
	}

	return I; // on retourne l'adresse de la ou l'allocation a ete faite
}
