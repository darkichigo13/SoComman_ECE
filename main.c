#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Goal.h"
#include "Constante.h"
/////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
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

/////////////////////////////////////////////////////////////////////////////////////////////
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
            jouer();
            printf("sortie du jouer/ menu");
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

/////////////////////////////////////////////////////////////////////////////////////////////
int jouer()
{
    int i=0;
    int j=0;
    int dimB=20;
    int dimP=20;
    int dimW=20;

    system("cls");
    int endgame;

    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    Box *tabBox = dynamicAllocBox(dimB);
    Player *tabPlayer = dynamicAllocPlayer(dimP);
    Wall *tabWall = dynamicAllocWall(dimW);

    // gestion des fichiers
    char nameText [] = "C:\\Users\\ELEVE\\Documents\\My_Sokoban\\SoComman_ECE\\terrain_1.txt";
                                                                                              printf("fichier : %s.txt\n\n",nameText);

    loadfile(nameText,matrice);

    for(i=0;i<nbRowsMatrix;i++)
    {
        for(j=0;j<nbColsMatrix;j++)
    {
        printf("%d",matrice[i][j]);
    }
    }


    while (endgame !=1)
    {
        system("cls");
        endgame = findWin(tabBox,dimB);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////////////
void implementationMatrice ( unsigned int matrice[nbRowsMatrix][nbColsMatrix],Box *tabBox,Player *tabPlayer,Wall *tabWall,int dimB,int dimP,int dimW)
{
    int i =0;
    for (i=0; i<dimB; i++)           // box implementation
    {
        if(tabBox[i].win=0)          // if not placed on a goal case
        {
            matrice[tabBox[i].pos_x][tabBox[i].pos_y]=3;
        }
    }
    for (i=0; i<dimW; i++)           // wall implementation
    {
        matrice[tabWall[i].pos_x][tabWall[i].pos_y]=2;
    }
    for (i=0; i<dimP; i++)            // player implementation
    {
        matrice[tabPlayer[i].pos_x][tabPlayer[i].pos_y]=10;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
void loadfile(char * name,  unsigned int matrice[nbRowsMatrix][nbColsMatrix])
{
    int i=0;
    int j=0;
    char caractereActuel;
    FILE* fichier = NULL;
                                                                                                    printf("avant transcription\n\n");
    fichier = fopen(name, "r+");
    if(fichier == NULL)
    {
       exit(0);
        printf("Impossible d'ouvrir le fichier %c.txt",name);
    }
    else
    {  printf("transcription en cours...\n\n");
        do
        {
            i++;
            do
            {
                j++;
                caractereActuel=fgetc(fichier);
                if (caractereActuel != '\n' || caractereActuel !='EOF')
                {
                    matrice[i][j]=caractereActuel;
                }                                                             printf("%c",caractereActuel);
            }
            while (caractereActuel != '\n' || caractereActuel !='EOF');
            printf("\n");
            printf("%c",caractereActuel);
        }
        while (caractereActuel != 'EOF');
    }



}
