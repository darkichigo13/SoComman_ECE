#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Player * dynamicAllocPlayer (int dim)
{
    printf("dimP = %d \n", dim);
    Player *tabPlayer= NULL;
    int i = 0;


    tabPlayer = malloc (dim * sizeof (Player));
    if (tabPlayer == NULL) // si l'allocation a �chou�
    {
        exit(0); // on arr�te imm�diatement le programme
    }

    // initialisation struct Player :
    for (i=0; i<dim; i++)
    {
        tabPlayer[i].pos_x=0;
        tabPlayer[i].pos_y=0;
        tabPlayer[i].case_dessous=1;
        tabPlayer[i].dirrection=0;
    }
    return tabPlayer;

}

void affichageTabPlayer (Player * tab, int dim)
{
    int i=0;

    for (i=0; i<dim; i++)
    {
        printf("Player posx : %d / Player posy : %d\n",tab[i].pos_x,tab[i].pos_y);
    }
}

bool movePlayer (Player *tabPlayer, char deplacement, Box *tabBox, Wall *tabWall, int dimB, int dimW)
{
    int i; //declare variable i
    int j; //declare variable j

    switch (deplacement)
    {

    case 'z' :
        for(i=0 ; i < dimB ; ++i)  // Parcours listes des Boxs
        {
            if(tabPlayer[0].pos_x - 1 == tabBox[i].pos_x && tabPlayer[0].pos_y == tabBox[i].pos_y)  // V�rifie que la case ou on veut se d�placer n'est pas une box
            {
                for(j=0 ; j < dimW ; ++j)  // Si c'est une box on parcours la liste des murs
                {
                    if(tabBox[i].pos_x - 1 == tabWall[j].pos_x && tabBox[i].pos_y == tabWall[j].pos_y)
                    {
                        printf("Impossible de se d�placer \n");// V�rifie que la case ou on veut d�placer la caisse n'est pas un mur
                        return false; // Et on renvoie false
                    }
                }
                tabBox[i].pos_x = tabBox[i].pos_x - 1; // Si la case � c�t� est vide on d�place la caisse de deux cases
                tabPlayer[0].pos_x = tabPlayer[0].pos_x - 1; // Puis on se d�place d'une case
                return true; // Et on renvoie true
            }
        }
        for(j=0 ; j < dimW ; ++j)  // Si la case � c�t� n'est pas une caisse
        {
            if(tabPlayer[0].pos_x - 1 == tabWall[j].pos_x && tabPlayer[0].pos_y == tabWall[j].pos_y)  // On v�rifie que ce n'est pas un mur
            {
                printf("Impossible de se d�placer \n"); // Si c'est un mur on affiche un message
                return false; // Et on renvoie false
            }
        }
        tabPlayer[0].pos_x = tabPlayer[0].pos_x - 1; // Si la case � c�t� n'est ni une caisse, ni un mur, on se d�place
        return true; // Et on renvoie true


    case 'q' :
        for(i=0 ; i < dimB ; ++i)  // Parcours listes des Boxs
        {
            if(tabPlayer[0].pos_x == tabBox[i].pos_x && tabPlayer[0].pos_y - 1 == tabBox[i].pos_y)  // V�rifie que la case ou on veut se d�placer n'est pas une box
            {
                for(j=0 ; j < dimW ; ++j)  // Si c'est une box on parcours la liste des murs
                {
                    if(tabBox[i].pos_x == tabWall[j].pos_x && tabBox[i].pos_y - 1 == tabWall[j].pos_y)
                    {
                        printf("Impossible de se d�placer \n");// V�rifie que la case ou on veut d�placer la caisse n'est pas un mur
                        return false; // Et on renvoie false
                    }
                }
                tabBox[i].pos_y = tabBox[i].pos_y - 1; // Si la case � c�t� est vide on d�place la caisse de deux cases
                tabPlayer[0].pos_y = tabPlayer[0].pos_y - 1; // Puis on se d�place d'une case
                return true; // Et on renvoie true
            }
        }
        for(j=0 ; j < dimW ; ++j)  // Si la case � c�t� n'est pas une caisse
        {
            if(tabPlayer[0].pos_x == tabWall[j].pos_x && tabPlayer[0].pos_y - 1 == tabWall[j].pos_y)  // On v�rifie que ce n'est pas un mur
            {
                printf("Impossible de se d�placer \n"); // Si c'est un mur on affiche un message
                return false; // Et on renvoie false
            }
        }
        tabPlayer[0].pos_y = tabPlayer[0].pos_y - 1; // Si la case � c�t� n'est ni une caisse, ni un mur, on se d�place
        return true; // Et on renvoie true


    case 's' :
        for(i=0 ; i < dimB ; ++i)  // Parcours listes des Boxs
        {
            if(tabPlayer[0].pos_x + 1 == tabBox[i].pos_x && tabPlayer[0].pos_y == tabBox[i].pos_y)  // V�rifie que la case ou on veut se d�placer n'est pas une box
            {
                for(j=0 ; j < dimW ; ++j)  // Si c'est une box on parcours la liste des murs
                {
                    if(tabBox[i].pos_x + 1 == tabWall[j].pos_x && tabBox[i].pos_y == tabWall[j].pos_y)
                    {
                        printf("Impossible de se d�placer \n");// V�rifie que la case ou on veut d�placer la caisse n'est pas un mur
                        return false; // Et on renvoie false
                    }
                }
                tabBox[i].pos_x = tabBox[i].pos_x + 1; // Si la case � c�t� est vide on d�place la caisse de deux cases
                tabPlayer[0].pos_x = tabPlayer[0].pos_x + 1; // Puis on se d�place d'une case
                return true; // Et on renvoie true
            }
        }
        for(j=0 ; j < dimW ; ++j)  // Si la case � c�t� n'est pas une caisse
        {
            if(tabPlayer[0].pos_x + 1 == tabWall[j].pos_x && tabPlayer[0].pos_y == tabWall[j].pos_y)  // On v�rifie que ce n'est pas un mur
            {
                printf("Impossible de se d�placer \n"); // Si c'est un mur on affiche un message
                return false; // Et on renvoie false
            }
        }
        tabPlayer[0].pos_x = tabPlayer[0].pos_x + 1; // Si la case � c�t� n'est ni une caisse, ni un mur, on se d�place
        return true;


    case 'd' :
        for(i=0 ; i < dimB ; ++i)  // Parcours listes des Boxs
        {
            if(tabPlayer[0].pos_x == tabBox[i].pos_x && tabPlayer[0].pos_y + 1 == tabBox[i].pos_y)  // V�rifie que la case ou on veut se d�placer n'est pas une box
            {
                for(j=0 ; j < dimW ; ++j)  // Si c'est une box on parcours la liste des murs
                {
                    if(tabBox[i].pos_x == tabWall[j].pos_x && tabBox[i].pos_y + 1 == tabWall[j].pos_y)
                    {
                        printf("Impossible de se d�placer \n");// V�rifie que la case ou on veut d�placer la caisse n'est pas un mur
                        return false; // Et on renvoie false
                    }
                }
                tabBox[i].pos_y = tabBox[i].pos_y + 1; // Si la case � c�t� est vide on d�place la caisse de deux cases
                tabPlayer[0].pos_y = tabPlayer[0].pos_y + 1; // Puis on se d�place d'une case
                return true; // Et on renvoie true
            }
        }
        for(j=0 ; j < dimW ; ++j)  // Si la case � c�t� n'est pas une caisse
        {
            if(tabPlayer[0].pos_x == tabWall[j].pos_x && tabPlayer[0].pos_y + 1 == tabWall[j].pos_y)  // On v�rifie que ce n'est pas un mur
            {
                printf("Impossible de se d�placer \n"); // Si c'est un mur on affiche un message
                return false; // Et on renvoie false
            }
        }
        tabPlayer[0].pos_y = tabPlayer[0].pos_y + 1; // Si la case � c�t� n'est ni une caisse, ni un mur, on se d�place
        return true; // Et on renvoie true

    }
}
