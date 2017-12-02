#include "Goal.h"
#include <stdlib.h>

Goal * dynamicAllocGoal (int dim)
{
    printf("dimB = %d \n", dim);
    Goal *tabGoal = NULL;
    int i = 0;


    tabGoal = malloc(dim * sizeof(Goal));
    if (tabGoal == NULL) // si l'allocation a �chou�
    {
        exit(0); // on arr�te imm�diatement le programme
    }

    // initialisation struct Goal :
    for (i=0; i<dim; i++)
    {
        tabGoal[i].pos_x=1;
        tabGoal[i].pos_y=1;
    }
    return tabGoal;

}
