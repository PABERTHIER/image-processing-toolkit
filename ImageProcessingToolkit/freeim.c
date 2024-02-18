#include "pro.h"

void freeim(imagex * I) { // liberer espace memoire pris par fonction freeim
	free(I->donnee[0]);
	free(I -> donnee); // liberation memoire des trois allocations faites par la fonction freeim
	free(I);
}
