#include "Player.h"
#include <stdlib.h>


// initialisation struct Player :
void initPlayer (Player* pointeur)
{
    pointeur->pos_x=0;
    pointeur->pos_y=0;
}
int alloctabPlayer (int dim)
{
    Player*pointeur = NULL;

    pointeur = malloc(dim*sizeof(Player));
    if (pointeur == NULL) // si l'allocation a �chou�
    {
        exit(0); // on arr�te imm�diatement le programme
    }

    // on peut continuer le programme normalement sinon

    return (pointeur);
}

