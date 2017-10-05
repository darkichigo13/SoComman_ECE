#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Goal.h"
#include "Constante.h"

int main()
{
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
        case 1 :
            jouer();                                                                    printf("sortie du jouer/ menu");
            break;
        case 2 :
            choix = option();
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
                                                                                        printf("sortie du menu");
    return (0);
}
int jouer()
{
    int i=0;
    int dimB=20;
    int dimP=20;
    int dimW=20;

    system("cls");
    int endgame;

    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    Box *tabBox = dynamicAllocBox(dimB);
    Player *tabPlayer = dynamicAllocPlayer(dimP);
    Wall *tabWall = dynamicAllocWall(dimW);

    while (endgame !=1)
    {
        system("cls");
        endgame = findWin(tabBox,20);
    }
}

int findWin(Box * tab, int dim)
{
    int i =0;
    int compter=0;
    for (i=0; i<dim; i++)
    {
        if (tab[i].win == 0) compter++;
    }
    if (compter == 0)
    {
        compter = 1;
    }
    else
    {
        compter = 0;
    }
    return (compter);
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

void implementationMatrice ( unsigned int matrice[nbRowsMatrix][nbColsMatrix],Box *tabBox,Player *tabPlayer,Wall *tabWall,int dimB,int dimP,int dimW,)
{
    int i =0;
    for (i=0;i<dimB;i++)
    {
        if(tabBox[i].win=0)
        {

        }
    }



}
