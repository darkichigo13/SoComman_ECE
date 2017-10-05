#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Goal.h"
#include "Constante.h"

int main()
{

    unsigned int matrice[nbRowsMatrix][nbColsMatrix];

    Player player;
    Player* pointeur = &player;
    initPlayer(pointeur);

    Player*pttab=0;
    int dim=20;

    pttab = alloctabPlayer(dim);

    printf("%d\n",player.pos_x);
    printf("%d\n\n",player.pos_y);
    return 0;
}


