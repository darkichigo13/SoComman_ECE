#include <stdbool.h>

typedef struct Box Box;
struct Box
   {
   char id[20];
   unsigned int pos_x;
   unsigned int pos_y;
   bool win;
   };
