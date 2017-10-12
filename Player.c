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
        tabPlayer[i].pos_x=0;
        tabPlayer[i].pos_y=0;
    }
    return tabPlayer;

}

void affichageTabPlayer (Player * tab, int dim)
{
    int i=0;

    for (i=0;i<dim;i++)
    {
    printf("Player posx : %d / Player posy : %d\n",tab[i].pos_x,tab[i].pos_y);
    }
}

