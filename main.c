#include <allegro.h>
#include <winalleg.h>
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Goal.h"
#include "Constante.h"
#include "allegro_Perso.h"



/////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

    menu();

    return 0;
}
END_OF_MAIN();

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
            menuJouer();
            break;
        case 2 :
            option();
            break;
        case 3 : system("cls");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("                          -       SOKOBAN       -                         \n");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("                           SANSHEZ PALMA DANIEL                         \n\n");
        printf("                              AMELINEAU LOUIS                           \n\n");
        printf("                                                                          \n");
        printf("                                                                          \n");
                Sleep(10000);
            break;
        case 4 :
            exit(EXIT_SUCCESS);
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
    printf("valeur de modeAffichage : %d\n",modeAffichage);
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
            if(modeAffichage==0)
            {
                choix = jouer(1,0);
            }
            if(modeAffichage=1)
            {
                choix = prejouerALLEGRO(1,0);
            }
            break;
        case 2 :
            if(modeAffichage==0)
            {
                choix = jouer(2,0);
            }
            if(modeAffichage==1)
            {
                choix = prejouerALLEGRO(2,0);
            }
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
int jouer(int A, int cpt)
{
    /////////////// delaration
    int endgame;
    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    int dimB=0;
    int dimP=0;
    int dimW=0;
    int dimG=0;

    char key;
    system("cls");

    if(A == 1)
    {
        loadfile(terrainFile1,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 2)
    {
        loadfile(saveFile1,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 4)
    {
        loadfile(terrainFile2,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 5)
    {
        loadfile(terrainFile3,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }

    Box *tabBox = dynamicAllocBox(dimB);
    Wall *tabWall = dynamicAllocWall(dimW);
    Player *tabPlayer = dynamicAllocPlayer(dimP);
    Goal *tabGoal = dynamicAllocGoal(dimG);

    int i;
    int j;
    int w = 0;
    int b = 0;
    int p = 0;
    int g = 0;

    for(i=0 ; i<nbRowsMatrix ; i++)
    {
        for(j=0 ; j<nbColsMatrix ; j++)
        {
            if(matrice[i][j] == 2)
            {
                tabWall[w].pos_x = i;
                tabWall[w].pos_y = j;
                w = w + 1;
                continue;
            }

            if(matrice[i][j] == 3)
            {
                tabBox[b].pos_x = i;
                tabBox[b].pos_y = j;
                b = b + 1;
                continue;
            }

            if(matrice[i][j] == 4)
            {
                tabPlayer[p].pos_x=i;
                tabPlayer[p].pos_y=j;
                p = p + 1;
                continue;
            }

            if(matrice[i][j] == 6)
            {
                tabGoal[g].pos_x=i;
                tabGoal[g].pos_y=j;
                g = g + 1;
                continue;
            }
        }
    }

    affichageTerrain(matrice,cpt);  // traitement en fonction du choix d'affige
    while (endgame !=1)
    {

        if(!kbhit())
        {

            key=getch();
            switch(key)
            {

            case 'z' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 'q' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 's' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 'd' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 'k' :
                jouer(A,0);
                break;

            case 'p' :
                saveFile(matrice);
                break;
            case 'm' :
                menu();
                break;


            }

            affichageTerrain(matrice,cpt); // traitement en fonction du choix d'affige
            cpt=cpt+1;
            endgame = findWin(tabBox, tabGoal, dimB, dimG);
        }
    }

    if( A == 1)
    {
        jouer(4,cpt);
    }
    else if( A == 4)
    {
        jouer(5,cpt);
    }


/////////////////////////////////////////////////////////////////////////////////////////////

    else if(A == 5)
    {
        system("cls");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("                          -       SOKOBAN       -                         \n");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("                                                                        \n\n");
        printf("  :::   :::  ::::::::  :::    :::       :::       ::: ::::::::::: ::::    :::  \n");
        printf("  :+:   :+: :+:    :+: :+:    :+:       :+:       :+:     :+:     :+:+:   :+:  \n");
        printf("   +:+ +:+  +:+    +:+ +:+    +:+       +:+       +:+     +:+     :+:+:+  +:+  \n");
        printf("    +#++:   +#+    +:+ +#+    +:+       +#+  +:+  +#+     +#+     +#+ +:+ +#+  \n");
        printf("     +#+    +#+    +#+ +#+    +#+       +#+ +#+#+ +#+     +#+     +#+  +#+#+#  \n");
        printf("     #+#    #+#    #+# #+#    #+#        #+#+# #+#+#      #+#     #+#   #+#+#  \n");
        printf("     ###     ########   ########          ###   ###   ########### ###    ####  \n");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("                               Score : %d                                 \n\n", cpt);

    }
    saveScore(cpt);

    Sleep(10000);

    menu();
}

void prejouerALLEGRO(int A,int cpt)
{
     srand(time(NULL));
    allegro_init();                      // initialisaiton d'allegro
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,WINDOH,WINDOL,0,0)!=0)
    {
        allegro_message("prb gfx mode\n");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    jouerALLEGRO(A,cpt);
}
/////////////////////////////////////////////////////////////////////////////////////////////
int jouerALLEGRO(int A,int cpt)
{
    int endgame;
    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    int dimB=0;
    int dimP=0;
    int dimW=0;
    int dimG=0;

    char key=0;
    int touche=0;
    int temp=0;

    system("cls");

    if(A == 1)
    {
        loadfile(terrainFile1,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 2)
    {
        loadfile(saveFile1,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 4)
    {
        loadfile(terrainFile2,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 5)
    {
        loadfile(terrainFile3,matrice);
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }


    BITMAP *buffer;
    buffer=create_bitmap(WINDOH,WINDOL);
    if (!buffer)
    {
        allegro_message("prb allocation BITMAP bmp \n");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    Box *tabBox = dynamicAllocBox(dimB);
    Wall *tabWall = dynamicAllocWall(dimW);
    Player *tabPlayer = dynamicAllocPlayer(dimP);
    Goal *tabGoal = dynamicAllocGoal(dimG);

    BITMAP **tabBitmap;                   // creation du tabeau de BITMAP
    tabBitmap=initTabBitmap();            // implémentation du tableau de BITMAP
    BITMAP *victoire;
    victoire = load_bitmap("victoire.bmp",NULL);
    if (!victoire)
    {
        printf("Couldn't load victoire.bmp!");
    }

    int i;
    int j;
    int w = 0;
    int b = 0;
    int p = 0;
    int g = 0;

    for(i=0 ; i<nbRowsMatrix ; i++)
    {
        for(j=0 ; j<nbColsMatrix ; j++)
        {
            if(matrice[i][j] == 2)
            {
                tabWall[w].pos_x = i;
                tabWall[w].pos_y = j;
                w = w + 1;
                continue;
            }

            if(matrice[i][j] == 3)
            {
                tabBox[b].pos_x = i;
                tabBox[b].pos_y = j;
                b = b + 1;
                continue;
            }

            if(matrice[i][j] == 4)
            {
                tabPlayer[p].pos_x=i;
                tabPlayer[p].pos_y=j;
                p = p + 1;
                continue;
            }

            if(matrice[i][j] == 6)
            {
                tabGoal[g].pos_x=i;
                tabGoal[g].pos_y=j;
                g = g + 1;
                continue;
            }
        }
    }

    affichageTerrainALLEGRO(matrice,tabBitmap,buffer,tabPlayer,cpt);  // traitement en fonction du choix d'affige

    while (endgame !=1)
    {

        if (keypressed())
        {
            system("cls");
            // récupérer la touche avec readkey() : équivalent allegro du getch()
            touche=readkey();

            // a partir de l'info de touche on obtient le caractère en castant en char
            key=(char)touche;
            switch(key)
            {

            case 'z' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                tabPlayer[0].dirrection=0;
                break;

            case 'q' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                tabPlayer[0].dirrection=1;
                break;

            case 's' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                tabPlayer[0].dirrection=2;
                break;

            case 'd' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                tabPlayer[0].dirrection=3;
                break;

            case 'k' :
                jouerALLEGRO(A,0);
                break;

            case 'p' :
                saveFile(matrice);
                break;
            case 'm' :
                 destroy_bitmap(victoire);
                 for(i=0; i<NIMAGE; i++)
                 {
                     destroy_bitmap(tabBitmap[i]);
                 }
                allegro_exit();
                menu();

                break;

            }

            affichageTerrainALLEGRO(matrice,tabBitmap,buffer,tabPlayer,cpt);  // traitement en fonction du choix d'affige
            cpt=cpt+1;
            endgame = findWin(tabBox, tabGoal, dimB, dimG);
        }
    }

    if( A == 1)
    {
        jouerALLEGRO(4,cpt);
    }
    else if( A == 4)
    {
        jouerALLEGRO(5,cpt);
    }
    else if(A == 5)
    {
        system("cls");

    clear_bitmap(screen);
    draw_sprite(screen,victoire,0,0);
    saveScore(cpt);
    Sleep(10000);

    allegro_exit();

    }
    menu();

}

////////////////////////////////////////////////////////////////////////////////////////////
int findWin(Box * tabBox, Goal * tabGoal, int dimB, int dimG)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    for (i=0; i<dimB; i++)
    {
        for (j=0; j<dimG; j++)
        {
            if(tabBox[i].pos_x == tabGoal[j].pos_x && tabBox[i].pos_y == tabGoal[j].pos_y)
            {
                tabBox[i].win = 1;
                tmp = tmp + 1;
            }
            else if(tmp == 0)
            {
                tabBox[i].win = 0;
            }
        }
    }

    int compter=0;
    for (i=0; i<dimB; i++)
    {
        if (tabBox[i].win == 0) compter++;
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
        case 1 :
            modeAffichage=0;
            choix=101;
            break;
        case 2 :
            modeAffichage=1;
            choix=101;
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
void implementationMatrice (unsigned int* matrice[nbRowsMatrix][nbColsMatrix],Box *tabBox,Player *tabPlayer, Goal *tabGoal, int dimB,int dimP, int dimG)
{
    int i;
    int j;

    for(i=0; i<nbRowsMatrix; i++)
    {
        for(j=0; j<nbColsMatrix; j++)
        {
            if(matrice[i][j] == 3)
            {
                matrice[i][j] = 1;
                continue;
            }

            if(matrice[i][j] == 4)
            {
                matrice[i][j] = 1;
                continue;
            }

        }
    }

    for (i=0; i<dimG; i++)            // player implementation
    {
        matrice[tabGoal[i].pos_x][tabGoal[i].pos_y] = 6;
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
void recupDimTabs( unsigned int matrice[nbRowsMatrix][nbColsMatrix], int* dimB, int* dimP, int* dimW, int* dimG)
{
    int i=0;
    int j=0;

    for(i=0; i<nbRowsMatrix; i++)
    {
        for(j=0; j<nbColsMatrix; j++)
        {
            if(matrice[i][j] == 2)
            {
                *dimW = *dimW + 1;
                continue;
            }

            if(matrice[i][j] == 3)
            {
                *dimB = *dimB + 1;
                continue;
            }

            if(matrice[i][j] == 4)
            {
                *dimP = *dimP + 1;
                continue;
            }

            if(matrice[i][j] == 6)
            {
                *dimG = *dimG + 1;
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
void affichageTerrainALLEGRO(unsigned int matrice[nbRowsMatrix][nbColsMatrix],BITMAP **tabBitmap, BITMAP *buffer,Player *tabPlayer,int cpt)
{
    int i=0;
    int j=0;
    for(i=0; i<nbRowsMatrix; i++)
    {
        for(j=0; j<nbColsMatrix; j++)
        {
            switch (matrice[i][j])
            {
            case 1 :                           // sol
                draw_sprite(buffer,tabBitmap[1],PICTH*j,PICTL*i);
                break;
            case 2 :                           // murs
                draw_sprite(buffer,tabBitmap[2],PICTH*j,PICTL*i);
                break;
            case 3 :                           // box
                draw_sprite(buffer,tabBitmap[4],PICTH*j,PICTL*i);
                break;
            case 4 : // perso
                draw_sprite(buffer,tabBitmap[1],PICTH*j,PICTL*i);
                switch(tabPlayer[0].dirrection)
                {
                case 0 :
                    draw_sprite(buffer,tabBitmap[6+(cpt%4)],PICTH*j,PICTL*i);
                    break;
                case 1 :
                    draw_sprite(buffer,tabBitmap[18+(cpt%4)],PICTH*j,PICTL*i);
                    break;
                case 2 :
                    draw_sprite(buffer,tabBitmap[14+(cpt%4)],PICTH*j,PICTL*i);
                    break;
                case 3 :
                    draw_sprite(buffer,tabBitmap[10+(cpt%4)],PICTH*j,PICTL*i);
                    break;

                }
                break;
            case 6 :                           // goal
                draw_sprite(buffer,tabBitmap[5],PICTH*j,PICTL*i);
                break;
            }
        }
    }
    draw_sprite(screen,buffer,0,0);
    clear_bitmap(buffer);
}

/////////////////////////////////////////////////////////////////////////////////////////////
void affichageTerrain(unsigned int matrice[nbRowsMatrix][nbColsMatrix],int cpt)
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
            case 6 :                           // goal
                printf("%c",goalpict);
                break;
            }
              }
    if(i == 2)
    {
        printf("        -       SOKOBAN       -");
    }
    if(i == 5)
    {
        printf("               Moves : %d", cpt);
    }
    else if(i == 8)
    {
        printf("                 Press :");
    }
    else if(i == 10)
    {
        printf("                   z");
    }
    else if(i == 11)
    {
        printf("                 q + d");
    }
    else if(i == 12)
    {
        printf("                   s");
    }
    else if(i == 14)
    {
        printf("                For move");
    }
    else if(i == 17)
    {
        printf("     press k to restart and m to leave");
    }
    printf("\n");
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////
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

void saveScore(int cpt)
{
    int previous_cpt;
    previous_cpt = loadScore();
    if(previous_cpt <= cpt)
    {
        printf("\n");
        printf("You not realize the best score (%d), try again !", previous_cpt);
    }

    else if(previous_cpt > cpt)
    {
        char tampon=0;
        FILE* fichier = NULL;
        fichier = fopen(savedScore, "w+");

        if (fichier == NULL)
        {
            printf("Impossible d'ouvrir le fichier :  %c.txt",savedScore);
            exit(0);
        }
        else
        {
            fprintf(fichier,"%d",cpt);
            printf("\n");
            printf("                            NEW BEST RECORD !!! \n\n");
            printf("                         previous best record : %d\n", previous_cpt);
            printf("                            new best record : %d", cpt);
        }
        fclose(fichier);
    }
}

int loadScore()
{
    int i, cpt;
    char tampon=0;
    FILE* fichier = NULL;
    fichier = fopen(savedScore, "r");
    if(fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier %c", savedScore);
        exit(0);
    }
    else
    {
        fscanf(fichier, "%d", &cpt);
    }
    fclose(fichier);

    return cpt;
}
