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



    printf("%d\n",player.pos_x);
    printf("%d\n\n",player.pos_y);
    return 0;
}


