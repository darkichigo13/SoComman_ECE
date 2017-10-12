#include "Player.h"
#include <stdlib.h>
#include <stdbool.h>

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

void movePlayer (Player *player, char deplacement){
    bool response;
    switch (deplacement){
    case 'z' :
        response = verifyMove(player->pos_x , (player->pos_y - 1));
        if (response){
            player->pos_y = player->pos_y - 1;
        }
        else if (!response){
            //TO-DO return error
        }

    case 'q' :
        response = verifyMove((player->pos_x - 1), player->pos_y);
        if (response){
            player->pos_x = player->pos_x - 1;
        }
        else if (!response){
            //TO-DO return error
        }

    case 's' :
        response = verifyMove(player->pos_x, (player->pos_y + 1));
        if (response){
            player->pos_y = player->pos_y + 1;
        }
        else if (!response){
            //TO-DO return error
        }

    case 'd' :
        response = verifyMove((player->pos_x + 1), player->pos_y);
        if (response){
            player->pos_x = player->pos_x + 1;
        }
        else if (!response){
            //TO-DO return error
        }
    }
}

bool verifyMove (int pos_x, int pos_y){
    //TO-DO
    return (1);
}
