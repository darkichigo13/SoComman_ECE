#include "Wall.h"

#include <stdio.h>
#include <stdlib.h>

Wall * dynamicAllocWall (int dimW)
{
    Wall *tabWall= NULL;
    int i = 0;
    int a = 0;

    tabWall = malloc(dimW * sizeof(Wall));

    if (tabWall == NULL) // si l'allocation a échoué
    {
        exit(0); // on arrête immédiatement le programme
    }

    // initialisation struct Wall :
    for (i=0; i<dimW; i++)
    {
        tabWall[i].pos_x=2;
        tabWall[i].pos_y=2;
        a=a+1;
    }

    return(tabWall);

}

/*void affichageTabWall(Wall * tab, int dim)
{
    int i=0;

    for (i=0;i<dim;i++)
    {
        printf("Wall posx : %d / Wall posy : %d\n", tab[i].pos_x,tab[i].pos_y);
    }
}*/

