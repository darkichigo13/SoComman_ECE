#include <allegro.h>
#include <winalleg.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "allegro_Perso.h"

BITMAP **initTabBitmap ()
{
    int i=0;
    BITMAP ** bmp=NULL;
    BITMAP *fullBitmap;



    bmp = malloc(sizeof(BITMAP*)*NIMAGE); // allocation mémoire du tableau de bitmap
    if (bmp == NULL) // Si l'allocation a échoué
    {
        printf("erreur allocation dynamique");
        exit(0); // On arrête immédiatement le programme
    }

    fullBitmap = load_bitmap("image.bmp",NULL);
    if (!fullBitmap)
    {
        printf("Couldn't load image.bmp!");
    }

    for(i=0; i<NIMAGE; i++)
    {
        bmp[i]=create_bitmap(WINDOH,WINDOL); // creation mémoire de l'ensemble des bitmap a la bonne taille
    }
    blit(fullBitmap,bmp[0],solTerreX,solTerreY,0, 0, PICTL,PICTH); // sol terre
    blit(fullBitmap,bmp[1],solSableX,solSableY,0, 0, PICTL,PICTH); // sol sable
    blit(fullBitmap,bmp[2],mur1X,mur1Y,0, 0, PICTL,PICTH);         // mur 1
    blit(fullBitmap,bmp[3],mur2X,mur2Y,0, 0, PICTL,PICTH);         // mur 2
    blit(fullBitmap,bmp[4],caisseX,caisseY,0, 0, PICTL,PICTH);     // caisse
    blit(fullBitmap,bmp[5],caseWinX,caseWinY,0, 0, PICTL,PICTH);   // case Win

    blit(fullBitmap,bmp[6],anniZ1X,anniZ1Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[7],anniZ2X,anniZ2Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[8],anniZ3X,anniZ3Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[9],anniZ4X,anniZ4Y,0, 0, PICTL,PICTH);

    blit(fullBitmap,bmp[10],anniQ1X,anniQ1Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[11],anniQ2X,anniQ2Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[12],anniQ3X,anniQ3Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[13],anniQ4X,anniQ4Y,0, 0, PICTL,PICTH);

    blit(fullBitmap,bmp[14],anniS1X,anniS1Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[15],anniS2X,anniS2Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[16],anniS3X,anniS4Y,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[17],anniS4X,anniS4Y,0, 0, PICTL,PICTH);

    blit(fullBitmap,bmp[18],185,0,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[19],185,31,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[20],185,62,0, 0, PICTL,PICTH);
    blit(fullBitmap,bmp[21],217,0,0, 0, PICTL,PICTH);

    return (bmp); // retour du pointeur du tableau de bitmap
}

