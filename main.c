#include <stdio.h>
#include <windows.h>
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

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
int menu ()
{
    system("cls");
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
            choix = menuJouer();
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
    return (0);
}

/////////////////////////////////////////////////////////////////////////////////////////////
int menuJouer ()
{
    system("cls");
    int choix=0;

    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                          -       SOKOBAN       -                         \n");
    printf("                                                                          \n");
    printf("                                                                          \n");
    printf("                                                                        \n\n");
    printf("                                1. Nouvelle partie     \n\n");
    printf("                                2. Charger partie    \n\n");
    printf("                                3. Menu    \n\n");

    while (choix !=101)
    {
        scanf("%d",&choix);
        switch (choix)
        {
        case 1 :
            choix = jouer(1);
            break;
        case 2 :
            choix = jouer(2);
            break;
        case 3 :
            choix = 101;
            break;
        default:
            choix =0;
            break;
        }
    }
    return (choix);
}

/////////////////////////////////////////////////////////////////////////////////////////////
int jouer(int A)
{
    /////////////// delaration
    int endgame;
    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    int dimB=0;
    int dimP=0;
    int dimW=0;

    char key;
    int temp;

    system("cls");

    if(A == 1)
    {
        loadfile(terrainFile1,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW);
    }
    if(A == 2)
    {
        loadfile(saveFile1,matrice);
    }

    Box *tabBox = dynamicAllocBox(dimB);
    Player *tabWall = dynamicAllocWall(dimW);
    Player *tabPlayer = dynamicAllocPlayer(dimP);

    int i;
    int j;
    int w = 0;
    int b = 0;
    int p = 0;

    for(i=0 ; i<nbRowsMatrix ; i++)
    {
        for(j=0 ; j<nbColsMatrix ; j++)
        {
            if(matrice[i][j] == 2){
                tabWall[w].pos_x = i;
                tabWall[w].pos_y = j;
                w = w + 1;
                continue;
            }

            if(matrice[i][j] == 3){
                tabBox[b].pos_x = i;
                tabBox[b].pos_y = j;
                b = b + 1;
                continue;
            }

            if(matrice[i][j] == 4){
                tabPlayer[p].pos_x=i;
                tabPlayer[p].pos_y=j;
                p = p + 1;
                continue;
            }
        }
    }

    affichageTerrain(matrice);

    printf("nombre de box  : %d \n", dimB);
    printf("nombre de wall : %d \n \n", dimW);

    // saveFile(matrice);

    while (endgame !=1)
    {
        if(!kbhit())
        {
            key=getch();
            switch(key){

            case 'z' :
                //printf("coordonnées de départ player : %d , %d \n", tabPlayer[0].pos_x, tabPlayer[0].pos_y);
                //printf("touche de déplacement : %c \n", key);
                printf("\n");
                printf("coordonnées avant rentre dans méthode de box 2 : %d, %d ", tabBox[2].pos_x, tabBox[2].pos_y);
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                //printf("coordonnées final player : %d , %d \n", tabPlayer[0].pos_x, tabPlayer[0].pos_y);
                implementationMatrice(matrice, tabBox, tabPlayer, dimB, dimP);
                /*printf("\n");
                printf("coordonnées box 0 : %d, %d ", tabBox[0].pos_x, tabBox[0].pos_y);
                printf("\n");
                printf("coordonnées box 1 : %d, %d ", tabBox[1].pos_x, tabBox[1].pos_y);
                printf("\n");
                printf("coordonnées box 2 : %d, %d ", tabBox[2].pos_x, tabBox[2].pos_y);
                printf("\n");
                printf("coordonnées box 3 : %d, %d ", tabBox[3].pos_x, tabBox[3].pos_y);*/
                break;

            case 'q' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                //implementationMatrice(matrice, tabBox, tabPlayer, dimB, dimP);
                break;

            case 's' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                //implementationMatrice(matrice, tabBox, tabPlayer, dimB, dimP);
                break;

            case 'd' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                //implementationMatrice(matrice, tabBox, tabPlayer, dimB, dimP);
                break;

            case 'p' :
                saveFile(matrice);
                break;
            }
            affichageTerrain(matrice);
        }
//        endgame = findWin(tabBox,pdimB);
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
void implementationMatrice (unsigned int* matrice[nbRowsMatrix][nbColsMatrix],Box *tabBox,Player *tabPlayer, int dimB,int dimP)
{
    int i;
    int j;

    for(i=0; i<nbRowsMatrix; i++)
    {
        for(j=0; j<nbColsMatrix; j++)
        {
            if(matrice[i][j] == 3){
                matrice[i][j] = 1;
                continue;
            }

            if(matrice[i][j] == 4){
                matrice[i][j] = 1;
                continue;
            }
        }
    }
    for (i=0; i<dimB; i++)           // box implementation
    {
        matrice[tabBox[i].pos_x][tabBox[i].pos_y] = 3;
    }

    for (i=0; i<dimP; i++)            // player implementation
    {
        matrice[tabPlayer[i].pos_x][tabPlayer[i].pos_y] = 4;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
void recupDimTabs( unsigned int matrice[nbRowsMatrix][nbColsMatrix], int* dimB, int* dimP, int* dimW)
{
    int i=0;
    int j=0;

    for(i=0; i<nbRowsMatrix; i++)
    {
        for(j=0; j<nbColsMatrix; j++)
        {
            if(matrice[i][j] == 2){
                *dimW = *dimW + 1;
                continue;
            }

            if(matrice[i][j] == 3){
                *dimB = *dimB + 1;
                continue;
            }

            if(matrice[i][j] == 4){
                *dimP = *dimP + 1;
                continue;
            }
        }
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
void loadfile(char * name,  unsigned int matrice[nbRowsMatrix][nbColsMatrix], int * pdimB, int * pdimP, int * pdimW)
{
    int i=0;
    int j=0;
    bool finfichier=0;
    char tampon[nbColsMatrix+1];
    FILE* fichier = NULL;
    fichier = fopen(name, "r+");
    if(fichier == NULL)
    {
        exit(0);
        printf("Impossible d'ouvrir le fichier %c",name);
    }
    else
    {

        for (i=0; i<nbRowsMatrix; i++)
        {
            fgets(tampon,(nbColsMatrix*nbRowsMatrix),fichier);

            for (j=0; j<nbColsMatrix; j++)
            {
                matrice[i][j]=(tampon[j]-48);
            }
        }
    }
    fclose(fichier);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void affichageTerrain(unsigned int matrice[nbRowsMatrix][nbColsMatrix])
{
    int i=0;
    int j=0;

    system("cls");

    for(i=0; i<nbRowsMatrix; i++)
    {
        for(j=0; j<nbColsMatrix; j++)
        {
            switch (matrice[i][j])
            {
            case 1 :                           // sol
                printf("%c",outdoorpict);
                break;
            case 2 :                           // murs
                printf("%c",wallpict);
                break;
            case 3 :                           // box
                printf("%c",florpict);
                break;
            case 4 :                           // perso
                printf("%c",persopict);
                break;
            }
        }
        printf("\n");
    }

}

void saveFile(unsigned int matrice[nbRowsMatrix][nbColsMatrix])
{
    int i,j;

    char tampon=0;
    FILE* fichier = NULL;
    fichier = fopen(saveFile1, "w+");

    if (fichier == NULL)
    {

        printf("Impossible d'ouvrir le fichier :  %c.txt",saveFile1);
        exit(0);
    }
    else
    {
        for (i=0; i<nbRowsMatrix; i++)
        {

            for (j=0; j<nbColsMatrix; j++)
            {
                fprintf(fichier,"%d",matrice[i][j]);


            }
            fputc('\n',fichier);
        }
        fclose(fichier);
    }
}
