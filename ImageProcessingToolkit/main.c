#include "pro.h"

int main() {
	imagex *im1;
	imagex *im4;

	copie("images/images_input/image1.txt"); // copie image (utilisant toutes les fonctions; allocation, lecture, ecriture et free)
	mhori("images/images_input/image1.txt"); // faire le miroir horizontale de notre image
	mverti("images/images_input/image1.txt"); // faire le miroir vertical de notre image
	jhori("images/images_input/image1.txt", im1); // faire la juxtaposition horizontale de notre image
	jverti("images/images_input/image1.txt", im4); // faire la juxtaposition verticale de notre image
	rot270("images/images_input/image1.txt"); // faire une rotation de 270 degres de notre image

	red("images/images_input/elephant.txt", "images/images_input/pont.txt"); // redimensionnement des images
	pmtoc("images/images_output/red1.txt", "images/images_output/red2.txt"); // cacher image message dans image de couverture
	restitute("images/images_output/pmtoc.txt"); // restituer image message depuis image de couverture

	return 0;
}
