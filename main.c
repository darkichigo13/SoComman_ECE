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
    int dim=20;

    Player *tabPlayer = dynamicAllocPlayer(dim);
    affichageTab(tabPlayer, dim);

    return 0;
}

