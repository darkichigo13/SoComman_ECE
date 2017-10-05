#include "Box.h"
#include <stdlib.h>


Box * dynamicAllocBox (int dim)
{
    Box *tabBox= NULL;
    int i = 0;


    tabBox = malloc (dim * sizeof (Box));
    if (tabBox == NULL) // si l'allocation a échoué
    {
        exit(0); // on arrête immédiatement le programme
    }

    // initialisation struct Box :
    for (i=0; i<dim; i++)
    {
        tabBox[i].pos_x=1;
        tabBox[i].pos_y=1;
        tabBox[i].win=0;
    }
    return tabBox;

}

void affichageTabBox (Box * tab, int dim)
{
    int i=0;

    for (i=0;i<dim;i++)
    {
    printf("Box posx : %d / Box posy : %d\n",tab[i].pos_x,tab[i].pos_y);
    }
}
