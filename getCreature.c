#include <stdlib.h>
#include <string.h>
#include "my_midgard.h"
#define NBCREA 5

static t_creature g_creatures[] =
 {
   {"Koopa", 1, 10, 10, 20, 20, NULL, NULL},
   {"Bob bomb", 1, 10, 10, 20, 20, NULL, NULL},
   {"Yoshi", 1, 10, 10, 20, 20, NULL, NULL},
   {"Maskas", 1, 10, 10, 20, 20, NULL, NULL},
   {"Kucco", 1, 10, 10, 20, 20, NULL, NULL},
   {NULL, 0, 0, 0, 0, 0, NULL, NULL}
 };

t_creature *getCreature()
{
 int        rnd;
 t_creature    *crea;
 rnd = rand() % NBCREA;
 if ((crea = malloc(sizeof(t_creature))) == NULL)
   return (NULL);
 crea->name = strdup(g_creatures[rnd].name);
 if (!crea->name)
   return (NULL);
 crea->lvl = g_creatures[rnd].lvl;
 crea->pv = g_creatures[rnd].pv;
 crea->pvmax = g_creatures[rnd].pvmax;
 crea->pm = g_creatures[rnd].pm;
 crea->pmmax = g_creatures[rnd].pmmax;
 crea->next = g_creatures[rnd].next;
 crea->prev = g_creatures[rnd].prev;
 return (crea);
}
