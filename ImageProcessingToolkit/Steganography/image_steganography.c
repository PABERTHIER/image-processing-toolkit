#include "pro.h"

/* We now propose to hide an image inside another image without altering them.
In reality, this concealment will modify the coverage data.
But this modification is too slight to be visible to the eye.
The process makes it possible to initially recover the data thus hidden.
We are going to hide an image (PGM) named message image, in another image (PGM) named cover image.
PGM images, where a pixel is encoded on one byte (8bits), have 256 shades of gray.
But the eye can only see about 40 shades of gray. So PGM images with 256 shades of gray use more bits than necessary.
From then on, it will be a question of using the unnecessary bits of the cover image, to hide the pixels of the message image.
No one will be able to see with these beautiful eyes the difference in the cover image thus modified.
To do this, we will use the least significant bits of the cover image.
More concretely, the least significant bits of the cover image will contain the pixels of the message image. */

/* Function to hide the message image within the cover image */
void hideMessage(char *coverFile, char *messageFile) {
    int i, j;
    images *coverImage;
    images *messageImage;
    FILE* coverFilePtr = NULL;
    FILE* outputFilePtr = NULL;
    
    // Open cover image file for reading
    coverFilePtr = fopen(coverFile, "r");
    if (coverFilePtr == NULL) {
        printf("Error: Unable to open cover image file.\n");
        return;
    }
    
    // Open output file for writing the modified cover image
    outputFilePtr = fopen("images/images_output/imtoc.txt", "w");
    if (outputFilePtr == NULL) {
        printf("Error: Unable to create output file.\n");
        fclose(coverFilePtr);
        return;
    }
    
    // Read the cover image
    coverImage = Lecture(coverFilePtr, coverFile);
    
    // Open message image file for reading
    FILE* messageFilePtr = fopen(messageFile, "r");
    if (messageFilePtr == NULL) {
        printf("Error: Unable to open message image file.\n");
        fclose(coverFilePtr);
        fclose(outputFilePtr);
        freeim(coverImage);
        return;
    }
    
    // Read the message image
    messageImage = Lecture(messageFilePtr, messageFile);
    
    // Close the message image file
    fclose(messageFilePtr);
    
    // Check if dimensions match
    if (coverImage->haut != messageImage->haut || coverImage->larg != messageImage->larg) {
        printf("Error: Message image dimensions do not match cover image dimensions.\n");
        fclose(coverFilePtr);
        fclose(outputFilePtr);
        freeim(coverImage);
        freeim(messageImage);
        return;
    }
    
    // Write header to output file
    fprintf(outputFilePtr, "P%c\n", coverImage->magn);
    fprintf(outputFilePtr, "%d %d\n", coverImage->larg, coverImage->haut);
    fprintf(outputFilePtr, "%d\n", coverImage->valm);
    
    // Embed message image into cover image
    for (i = 0; i < coverImage->haut; i++) {
        for (j = 0; j < coverImage->larg; j++) {
            // Hide message in least significant bit of cover image pixel
            coverImage->donnee[i][j].r = (coverImage->donnee[i][j].r & 0xFE) | (messageImage->donnee[i][j].r & 0x01);
            // Write modified pixel to output file
            fprintf(outputFilePtr, "%d ", coverImage->donnee[i][j].r);
        }
        fprintf(outputFilePtr, "\n");
    }
    
    // Close files and free memory
    fclose(coverFilePtr);
    fclose(outputFilePtr);
    freeim(coverImage);
    freeim(messageImage);
}
