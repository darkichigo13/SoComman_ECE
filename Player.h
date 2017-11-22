#include <stdbool.h>

typedef struct Player Player;
struct Player
   {
   char name[20];
   unsigned int pos_x;
   unsigned int pos_y;
   int case_dessous;
   int case_cible;
   };

bool verifyMove(int pos_x, int pos_y);
