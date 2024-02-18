#include "pro.h"
typedef char byte;

/* Ecrire la procédure qui permet de restituer l’image message depuis l’image de couverture */

void restitute(char *fichier) {
	int i, j, k;
	char a[8] = {0};
	byte masque1[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80}; // 00000001;    byte à 1
	byte masque2[8] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F}; // 11111110;    byte à 0
	images *im;
	FILE *f = NULL;
	FILE *f1 = NULL;
	f1 = fopen("images/images_output/restitute.txt", "w"); // creation nouveau fichier texte pour y ecrire la nouvelle photo obtenue
	im = Lecturepgm(f, fichier);
	fprintf(f1, "P%c\n", im->magn); // ecriture de l'entête dans le fichier
	fprintf(f1, "%d %d\n", im->larg / 8, im->haut); // ecriture de la largeur de l'image et de la hauteur
	fprintf(f1, "%d\n", im->valm); // ecriture de la valeur maximale

	for (i = 0; i < im->haut; i++) {
		for (j = 0; j < im->larg / 8; j++) {
			im->donnee[i][j] = im->donnee[i][j] & masque2[6];
			fprintf(f1, "%d ", im->donnee[i][j]);
		}

		fprintf(f1, "\n");
	}

	/*test    
	for(i=0;i<im->haut;i++){
		for(j=0;j<im->larg/8;j++){
			for(k=0;k<8;k++){
				if (!(im->donnee[i][j+k] & masque1[k]))
				{
					a[k] = im->donnee[i][j+k] & masque1[k];
					// fprintf(f1,"%d ",im->donnee[i][j+k]);
				}
				//else
				//{
				//  im->donnee[i][j+k] = im->donnee[i][j+k] & masque2[0];
				//  fprintf(f1,"%d ",(im->donnee[i][j+k]));
				//}
			}
			for(k=0;k<8;k++){
				im->donnee[i][j] += a[k];
			}

			fprintf(f1,"%d ",im->donnee[i][j]);
		}

		fprintf(f1,"\n");                            
	}
	*/

	fclose(f1);
	freeimpgm(im); // liberer memoire prise par les im de type images

	return;
}
