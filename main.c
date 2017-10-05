#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Goal.h"
#include "Constante.h"

int main()
{
    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    int i=0;
    int dim=2;

    Player *tabPlayer = dynamicAllocPlayer(dim);
    affichageTabPlayer(tabPlayer, dim);
printf("\n\n");
    Box *tabBox = dynamicAllocBox(dim);
    affichageTabBox(tabBox, dim);
printf("\n\n");
    Wall *tabWall = dynamicAllocWall(dim);
    affichageTabWall(tabWall, dim);
menu();

    /*while(!kbhit()){
        char key = getchar();

        switch(key){
            case('z'):
                printf("%c",key);
                break;

            case('q'):
                printf("%c",key);
                break;

            case('s'):
                printf("%c",key);
                break;

            case('d'):
                printf("%c",key);
                break;
        }
    }*/

    return 0;
}
int menu ()
{
    system("cls");
    printf("##########################################################################\n");
    printf("##########################################################################\n");
    printf("##########################################################################\n");
    printf("#############                 SOKOBAN                     ################\n");
    printf("##########################################################################\n");
    printf("##########################################################################\n");
    printf("##########################################################################\n\n");
    printf("                                1. Jouer");
    printf("                                2. P");
    return (0);
}
