#include "Player.h"


// initialisation struct Player :
void initPlayer (Player* pointeur)
{
    pointeur->pos_x=20;
    pointeur->pos_y=21;
}
int alloctabPlayer (Player*pointeur, int dim)
{
    pointeur = null;

    pointeur = malloc(dim*sizeof(player));
    if (pointeur == null) // si l'allocation a �chou�
    {
        exit(0); // on arr�te imm�diatement le programme
    }

    // on peut continuer le programme normalement sinon

    return (pointeur);
}

