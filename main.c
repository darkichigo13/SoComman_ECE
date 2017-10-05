#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Goal.h"

int main()
{
    Player player;
    Player* pointeur = &player;
    initPlayer(pointeur);

    Player*pttab=0;
    int dim=20;

    pttab = alloctabPlayer(dim);

    pttab



    printf("%d\n",player.pos_x);
    printf("%d\n\n",player.pos_y);
    return 0;
}


