#include "Wall.h"

#include <stdlib.h>

Wall * dynamicAllocWall (int dim)
{
    Wall *tabWall= NULL;
    int i = 0;


    tabWall = malloc (dim * sizeof (Wall));
    if (tabWall == NULL) // si l'allocation a �chou�
    {
        exit(0); // on arr�te imm�diatement le programme
    }

    // initialisation struct Wall :
    for (i=0; i<dim; i++)
    {
        tabWall[i].pos_x=2;
        tabWall[i].pos_y=2;
    }
    return tabWall;

}

void affichageTabWall(Wall * tab, int dim)
{
    int i=0;

    for (i=0;i<dim;i++)
    {
    printf("posx : %d / posy : %d\n",tab[i].pos_x,tab[i].pos_y);
    }
}

