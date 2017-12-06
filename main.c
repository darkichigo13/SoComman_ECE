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




int main()
{

    menu(); // lancement du jeu

    return 0;
}
END_OF_MAIN();  // fin allegro

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
        case 3 :
            system("cls");
            printf("                                                                          \n");
            printf("                                                                          \n");
            printf("                                                                          \n");
            printf("                          -       SOKOBAN       -                         \n");
            printf("                                                                          \n");
            printf("                                                                          \n");
            printf("                           SANCHEZ PALMA DANIEL                         \n\n");
            printf("                              AMELINEAU LOUIS                           \n\n");
            printf("                                                                          \n");
            printf("                                                                          \n");
            Sleep(10000);
            break;
        case 4 :
            exit(EXIT_SUCCESS); // on quitte le programme
            break;
        default:
            choix =0;
            break;
        }
    }
    return (0);
}

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
            if(modeAffichage==0) // selection du mode d'affichage en fonction du choix utilisateur
            {
                choix = jouer(1,0); // affichage console
            }
            if(modeAffichage=1)
            {
                choix = prejouerALLEGRO(1,0); // affichage allegro
            }
            break;
        case 2 :
            if(modeAffichage==0)// selection du mode d'affichage en fonction du choix utilisateur
            {
                choix = jouer(2,0);  // affichage console
            }
            if(modeAffichage==1)
            {
                choix = prejouerALLEGRO(2,0);  // affichage allegro
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

int jouer(int A, int cpt) // fonction de jeu
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

    if(A == 1)  // chargement du niveau désiré
    {
        loadfile(terrainFile1,matrice); // niveau 1
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 2)
    {
        loadfile(saveFile1,matrice);  // niveau sauvegardé
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 4)
    {
        loadfile(terrainFile2,matrice);  // niveau 2
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }
    if(A == 5)
    {
        loadfile(terrainFile3,matrice);  // niveau 3
        recupDimTabs(matrice, &dimB, &dimP, &dimW, &dimG);
    }

        // déclaration des tableaux de structure contenant nos différents éléments
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

    for(i=0 ; i<nbRowsMatrix ; i++) // remplisage des tabeaux avec les valeurs charger dans la matrice
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
    while (endgame !=1) // boucle de jeu
    {

        if(!kbhit())   // si un touche est frappée
        {

            key=getch(); // récupération de la touche frappé
            switch(key)
            {

            case 'z' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW); // appelle de la fonction de vérification de déplacement et de modification des coordonnées des élélments de jeu
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 'q' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);// appelle de la fonction de vérification de déplacement et de modification des coordonnées des élélments de jeu
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 's' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);// appelle de la fonction de vérification de déplacement et de modification des coordonnées des élélments de jeu
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 'd' :
                movePlayer(tabPlayer, key, tabBox, tabWall, dimB, dimW);// appelle de la fonction de vérification de déplacement et de modification des coordonnées des élélments de jeu
                implementationMatrice(matrice, tabBox, tabPlayer, tabGoal, dimB, dimP, dimG);
                break;

            case 'k' :
                jouer(A,0); // réinitialisation du niveau
                break;

            case 'p' :
                saveFile(matrice); // sauvegarde de la partie en cours
                break;
            case 'm' :
                menu(); // retour menu
                break;


            }

            affichageTerrain(matrice,cpt); // traitement en fonction du choix d'affige
            cpt=cpt+1;
            endgame = findWin(tabBox, tabGoal, dimB, dimG); // fonction de teste de fin de partie
        }
    }

    if( A == 1) // en fonction du niveau actuel on charge le suivant
    {
        jouer(4,cpt);
    }
    else if( A == 4)
    {
        jouer(5,cpt);
    }


/////////////////////////////////////////////////////////////////////////////////////////////

    else if(A == 5) // affichage de l'écran de victoire si on fini le jeu
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
    saveScore(cpt); // sauvegarde du score

    Sleep(10000); // temporisation

    menu(); // retour menu
}

void prejouerALLEGRO(int A,int cpt) // initialisation du mode allegro
{
    srand(time(NULL));
    allegro_init();                      // initialisaiton d'allegro
    install_keyboard();
   // extern FONT *font; // déclaration police d'écriture

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,WINDOH,WINDOL,0,0)!=0)
    {
        allegro_message("prb gfx mode\n");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    jouerALLEGRO(A,cpt); // appelle de la fonciton jouer allegro
}

int jouerALLEGRO(int A,int cpt) // fonciton de jeu en mode allegro
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

    if(A == 1)  // chargement du niveau désiré
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


    BITMAP *buffer; // déclaration des ressources allegro
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
    int buffscore=0;
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
     A=5;
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

        clear_bitmap(screen); // réinitialisation du screen
        draw_sprite(screen,victoire,0,0); // affichage de la bitmap de victoire
        buffscore=loadScore();

        textprintf_centre_ex(screen, font, 380, 430, makecol(50,255,140), 0, "BEST SCORE = %d", buffscore); // affichage du score sauvegarder
        textprintf_centre_ex(screen, font, 380, 460, makecol(255,140,50), 0, " YOUR SCORE = %d ", cpt); // affichage du score du joueur

        saveScore(cpt); // sauvegarde du score
        Sleep(10000); // temporisation

        allegro_exit(); // fin allegro

    }
    menu(); // retour menu

}

int findWin(Box * tabBox, Goal * tabGoal, int dimB, int dimG) // test de fin de partie
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    for (i=0; i<dimB; i++) // parcour du tableau de box pour savoir si elles sont posées
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

int option () // sous menu d'option utilisateur
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

void implementationMatrice (unsigned int* matrice[nbRowsMatrix][nbColsMatrix],Box *tabBox,Player *tabPlayer, Goal *tabGoal, int dimB,int dimP, int dimG) // fonction de chargement de la matrice de terrain depuis un fichier
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

void recupDimTabs( unsigned int matrice[nbRowsMatrix][nbColsMatrix], int* dimB, int* dimP, int* dimW, int* dimG) // décupération du nombre d'éléments de chaque type
{
    int i=0;
    int j=0;

    for(i=0; i<nbRowsMatrix; i++) // parcours de la matrice
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

void loadfile(char * name,  unsigned int matrice[nbRowsMatrix][nbColsMatrix], int * pdimB, int * pdimP, int * pdimW)// fonction de parcours du fichier et de replisage de la matrice
{
    int i=0;
    int j=0;
    bool finfichier=0;
    char tampon[nbColsMatrix+1]; // tampon de lecture des caractères du fichier
    FILE* fichier = NULL;
    fichier = fopen(name, "r+"); // ouverture du fichier
    if(fichier == NULL) // vérification de l'ouverture
    {
        printf("Impossible d'ouvrir le fichier %c",name);
        exit(0); // si fail : fermeture du programme
    }
    else
    {

        for (i=0; i<nbRowsMatrix; i++) // conversion ascii
        {
            fgets(tampon,(nbColsMatrix*nbRowsMatrix),fichier); // parcours du fichier

            for (j=0; j<nbColsMatrix; j++)
            {
                matrice[i][j]=(tampon[j]-48);
            }
        }
    }
    fclose(fichier); // fermeture du fichier
}

void affichageTerrainALLEGRO(unsigned int matrice[nbRowsMatrix][nbColsMatrix],BITMAP **tabBitmap, BITMAP *buffer,Player *tabPlayer,int cpt)// fonction d'affichage graffique
{
    int i=0;
    int j=0;
    for(i=0; i<nbRowsMatrix; i++)
    {
        for(j=0; j<nbColsMatrix; j++)
        {
            switch (matrice[i][j]) // choix de la bitmap a afficher
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

                switch(tabPlayer[0].dirrection) // choix de l'orientation du personnage
                {
                case 0 :
                    draw_sprite(buffer,tabBitmap[6+(cpt%4)],PICTH*j,PICTL*i); // choix de la frame de l'annimation a affichier
                    break;
                case 1 :
                    draw_sprite(buffer,tabBitmap[18+(cpt%4)],PICTH*j,PICTL*i);// choix de la frame de l'annimation a affichier
                    break;
                case 2 :
                    draw_sprite(buffer,tabBitmap[14+(cpt%4)],PICTH*j,PICTL*i);// choix de la frame de l'annimation a affichier
                    break;
                case 3 :
                    draw_sprite(buffer,tabBitmap[10+(cpt%4)],PICTH*j,PICTL*i);// choix de la frame de l'annimation a affichier
                    break;

                }
                break;
            case 6 :                           // goal
                draw_sprite(buffer,tabBitmap[5],PICTH*j,PICTL*i); // affichage des goal
                break;
            }
        }
    }
    draw_sprite(screen,buffer,0,0); // affichage de l'image final sur l'écran
    textprintf_centre_ex(screen, font, 700, 100, makecol(255,140,50), 0, "SCORE = %d ", cpt); // affichage du score
    clear_bitmap(buffer); // supréssion du buffer
}

void affichageTerrain(unsigned int matrice[nbRowsMatrix][nbColsMatrix],int cpt) // affichage terrain en mode console
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
        if(i == 2) // mise en place de l'interface utilisateur du mode console
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

void saveFile(unsigned int matrice[nbRowsMatrix][nbColsMatrix]) // fonction de sauvegade de la partie en cour
{
    int i,j;

    char tampon=0;
    FILE* fichier = NULL; // pointeur sur le fichier
    fichier = fopen(saveFile1, "w+"); // ouverture du fichier en mode écriture

    if (fichier == NULL) // vérification de l'ouverture du fichier
    {

        printf("Impossible d'ouvrir le fichier :  %c.txt",saveFile1);
        exit(0);// quitter le programme si non ouverture
    }
    else
    {
        for (i=0; i<nbRowsMatrix; i++) // parcours de la matrice
        {

            for (j=0; j<nbColsMatrix; j++)
            {
                fprintf(fichier,"%d",matrice[i][j]); // écriture de la matrice dans le fichier


            }
            fputc('\n',fichier); // retoure a la ligne dans le fichier
        }
        fclose(fichier); // fermeture du fichier
    }
}

void saveScore(int cpt) // fonction de sauvegarde du score
{
    int previous_cpt;
    previous_cpt = loadScore();
    if(previous_cpt <= cpt) // comparaison pour écrire que le meilleur score
    {
        printf("\n");
        printf("You not realize the best score (%d), try again !", previous_cpt);
    }

    else if(previous_cpt > cpt)
    {
        char tampon=0;
        FILE* fichier = NULL;
        fichier = fopen(savedScore, "w+"); // ouverture du fichier de score

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

int loadScore() // fonction de lecture du meilleur score dans le fichier de score
{
    int i, cpt;
    char tampon=0;
    FILE* fichier = NULL;
    fichier = fopen(savedScore, "r");
    if(fichier == NULL) // ouverture du fichier
    {
        printf("Impossible d'ouvrir le fichier %c", savedScore);
        exit(0); // quitter si non ouverture
    }
    else
    {
        fscanf(fichier, "%d", &cpt); // lecture du score
    }
    fclose(fichier); // fermeture du fichier

    return cpt; // retour du score
}
