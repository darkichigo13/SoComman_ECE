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

    int i=0;
    int dim=2;

    Player *tabPlayer = dynamicAllocPlayer(dim);
    affichageTabPlayer(tabPlayer, dim);
printf("\n\n");
    Box *tabBox = dynamicAllocBox(dim);
    affichageTabBox(tabBox, dim);
printf("\n\n");
    Wall *tabWall = dynamicAllocWall(dim);
    affichageTabWall(tabWall, dim);

    return 0;
}

