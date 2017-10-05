#include "Player.h"
#include <stdlib.h>


// initialisation struct Player :
void initPlayer (Player* pointeur)
{
    pointeur->pos_x=20;
    pointeur->pos_y=21;
}
int alloctabPlayer (Player*pointeur, int dim)
{
    pointeur = NULL;

    pointeur = malloc(dim*sizeof(Player));
    if (pointeur == NULL) // si l'allocation a échoué
    {
        exit(0); // on arrête immédiatement le programme
    }

    // on peut continuer le programme normalement sinon

    return (pointeur);
}

