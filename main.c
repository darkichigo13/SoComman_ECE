#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Box.h"
#include "Wall.h"
#include "Goal.h"

int main()
{
    int i=0;
    int dim=20;

    Player *tabPlayer = dynamicAllocPlayer(dim);
    affichageTab(tabPlayer, dim);


    return 0;
}

