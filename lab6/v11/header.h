#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct patient {
   unsigned short age;
   struct name {char *first; char *last;} pname;
   struct height {int feet; int inches;} pheight;
   unsigned int weight;
   bool purduegraduate;
   struct patient *next;
} patient_t;