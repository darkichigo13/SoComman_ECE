#include "Player.h"
#include <stdlib.h>

Player * dynamicAllocPlayer (int dim)
{
    Player *tabPlayer= NULL;
    int i = 0;


    tabPlayer = malloc (dim * sizeof (Player));
    if (tabPlayer == NULL) // si l'allocation a échoué
    {
        exit(0); // on arrête immédiatement le programme
    }

    // initialisation struct Player :
    for (i=0; i<dim; i++)
    {
        tabPlayer[i].pos_x=1;
        tabPlayer[i].pos_y=1;
    }
    return tabPlayer;

}

void affichageTab (Player * tab, int dim)
{
    int i=0;

    for (i=0;i<dim;i++)
    {
    printf("posx : %d / posy : %d\n",tab[i].pos_x,tab[i].pos_y);
    }
}
