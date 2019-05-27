#include <stdlib.h>
#include <stdio.h>
#include "funkcije.h"

void pisi_clanak(n_clanak clanak)
{
    printf("ID: %d\n",clanak.id);
    printf("Naslov: %s\n",clanak.naslov);
    printf("Casopis: %s\n",clanak.casopis);
    printf("Godina: %d\n",clanak.godina);
    printf("*****************\n");
}

void pisi(cvor *prvi)
{
    printf("\n");
    while(prvi)
    {
        pisi_clanak(prvi->clanak);
        prvi = prvi->sl;
    }
}