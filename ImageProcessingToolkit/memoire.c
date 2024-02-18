#include "pro.h" // modulaire, en lien avec pro.h (prototypes, struct...)

imagex *memoire(int x, int y) { // fonction qui réalise l’allocation en mémoire pour une image de format PPM
	int i; // initialisation
	imagex *I = (imagex *)malloc(sizeof(imagex)); // allocation de memoire a la variable de type imagex*
	I->larg = x; // largeur
	I->haut = y; // hauteur
	I->donnee = (impix **)malloc(y * sizeof(impix *)); // allocation de memoire pour les donnee de I

	impix *imp = (impix *)malloc(x * y * sizeof(impix)); // allocation de memoire pour les attributions de couleur rouge, vert, bleu

	for (i = 0; i < y; i++) {
		I->donnee[i] = imp + x * i; // taille de la matrice
	}

	return I; // on retourne l'adresse de la ou l'allocation a ete faite
}
