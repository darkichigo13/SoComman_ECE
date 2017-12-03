#include <stdbool.h>

typedef struct Box Box;
struct Box
   {
   int id;
   unsigned int pos_x;
   unsigned int pos_y;
   bool win;
   };
