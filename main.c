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
    system("cls");
    int endgame;

    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    Box *tabBox = dynamicAllocBox(dimB);
    Player *player;
    Wall *tabWall = dynamicAllocWall(dimW);

    loadfile(terrainFile1 ,matrice);

    affichageTerrain(matrice);

    saveFile(matrice);

    printf("save ok");

    loadfile(saveFile1, matrice);

    affichageTerrain(matrice);
     printf("load save ok");

    while (endgame !=1)
    {
        while(!kbhit()){
        char key = getchar();
        bool response;

        switch(key){
            case('z'):
                response = movePlayer(player, key, tabBox, tabWall); // Déplace le joueur si possible
                if(response){ // Si le déplacement est possible on réactualise l'affichage
                    affichageTerrain(matrice);
                }
                else{ // Si le déplacement est impossible on fait un affichage spécial
                    //affichageImpossibilitéDeplacement();
                }
                break;

            case('q'):
                response = movePlayer(player, key, tabBox, tabWall); // Déplace le joueur si possible
                if(response){ // Si le déplacement est possible on réactualise l'affichage
                    affichageTerrain(matrice);
                }
                else{ // Si le déplacement est impossible on fait un affichage spécial
                    //affichageImpossibilitéDeplacement();
                }
                break;

            case('s'):
                response = movePlayer(player, key, tabBox, tabWall); // Déplace le joueur si possible
                if(response){ // Si le déplacement est possible on réactualise l'affichage
                    affichageTerrain(matrice);
                }
                else{ // Si le déplacement est impossible on fait un affichage spécial
                    //affichageImpossibilitéDeplacement();
                }
                break;

            case('d'):
                response = movePlayer(player, key, tabBox, tabWall); // Déplace le joueur si possible
                if(response){ // Si le déplacement est possible on réactualise l'affichage
                    affichageTerrain(matrice);
                }
                else{ // Si le déplacement est impossible on fait un affichage spécial
                    //affichageImpossibilitéDeplacement();
                }
                break;
        }
    }
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
    bool finfichier=0;
    char tampon[nbColsMatrix+1];
    FILE* fichier = NULL;
    fichier = fopen(name, "r+");
    if(fichier == NULL)
    {
        exit(0);
        printf("Impossible d'ouvrir le fichier %c.txt",name);
    }
    else
    {
        //  printf("transcription en cours de X= %d ; Y= %d\n\n",nbRowsMatrix,nbColsMatrix);

        for (i=0; i<nbRowsMatrix; i++)
        {
            fgets(tampon,(nbColsMatrix*nbRowsMatrix),fichier);

            for (j=0; j<nbColsMatrix; j++)
            {
                matrice[i][j]=(tampon[j]-48);
                //printf("%d", matrice[i][j]);
            }
            //printf("\n");
        }
    }

    //printf(" - fin importation du terrain - \n\n");

    fclose(fichier);
   // printf(" - fin importation suppretion fichier -\n");

}

/////////////////////////////////////////////////////////////////////////////////////////////
void affichageTerrain(unsigned int matrice[nbRowsMatrix][nbColsMatrix])
{
    int i=0;
    int j=0;

  //  system("cls");

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
            case 3 :                           // sol
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


            } fputc('\n',fichier);
        }
fclose(fichier);
}
}
