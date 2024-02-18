#include "pro.h"

void freeimpgm(images * I) { // liberer espace memoire pris par fonction freeim
	free(I -> donnee); // liberation memoire des trois allocations faites par la fonction freeim
	free(I);
}
