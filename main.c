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

    return 0;
}
int menu ()
{
    int choix=0;

    while (choix !=100)
    {
    system("cls");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                          -       SOKOBAN       -                         \n");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                                                                        \n\n");
    printf("                                1. Jouer     \n\n");
    printf("                                2. Option    \n\n");
    printf("                                3. Credit    \n\n");
    printf("                                4. Quitter    \n\n");

        scanf("%d",&choix);
        switch (choix)
        {
        case 1 : // jouer
            break;
        case 2 :  choix = option();
            break;
        case 3 : //  Credit
            break;
        case 4 :
            exit(0);// quitter
            break;
        default:
            choix =0;
            break;
        }
    }
    return (0);
}

int option ()
{
    int choix=0;

    while (choix !=101)
    {

    system("cls");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                          -       SOKOBAN       -                         \n");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                                                                        \n\n");
    printf("                                1. Affichage console     \n\n");
    printf("                                2. Affichage Allegro    \n\n");
    printf("                                3. Musique On/Off    \n\n");
    printf("                                4. Retour    \n\n");

        scanf("%d",&choix);
        switch (choix)
        {
        case 1 : // affichage console
            break;
        case 2 :  // affichage allegro
            break;
        case 3 : //  musique
            break;
        case 4 :
            choix = 101; // retour
            break;
        default:
            choix = 0;
            break;
        }
    }

    return(choix);
}

