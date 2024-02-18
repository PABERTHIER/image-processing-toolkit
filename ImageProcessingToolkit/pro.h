#ifndef pro_h
#define pro_h

#include <stdio.h>
#include <stdlib.h>

struct images // images de types PBM et PGM
{
	int magn; // l'entier entête du fichier P1, P2
	int larg; // la largeur de l'image de type int
	int haut; // la hauteur de l'image de type int
	int valm; // la valeur maximale de type int
	int **donnee; // de type int **
};

typedef struct images images;

struct impix
{
	int r; // la couleur primaire rouge de type int
	int v; // la couleur primaire verte de type int
	int b; // la couleur primaire bleue de type int
};

typedef struct impix impix;

struct imagex // images de type PPM
{
	char magn; // l'entête du fichier P3
	int larg; // la largeur de l'image de type int
	int haut; // la hauteur de l'image de type int
	int valm; // la valeur maximale de type int
	impix **donnee; // de type impix **
};

typedef struct imagex imagex;

imagex *memoire(int x, int y);
imagex *Lecture(FILE *, char *);
void Write(imagex *); // prototypes fonctions
void freeim(imagex *);
void copie(char *);
imagex *mhori(char *fichier);
void mverti(char *fichier);
void jhori(char *fichier, imagex *);
void jverti(char *fichier, imagex *);
void rot270(char *fichier);
images *memoirepgm(int x, int y);
images *Lecturepgm(FILE *, char *);
void Writepgm(images *);
void copiepgm(char *);
void freeimpgm(images *);
void pmtoc(char *fichier, char *fichier2);
void red(char *fichier, char *fichier1);
void restitute(char *fichier);

#endif
