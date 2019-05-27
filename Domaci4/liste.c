#include <stdlib.h>
#include <string.h>
#include "funkcije.h"

void brisi(cvor *prvi)
{
    cvor *t;
    while (prvi)
    {
        t = prvi;
        prvi = prvi->sl;
        free(t);
    }
}

//Izbacuje clanak sa proslednjenim id-jem
//Pretpostavka je da su id-vi clanaka jedinstveni
void izbaci(cvor **prvi,int clanak_id)
{
    cvor *last = NULL, *t = *prvi;
    while(t != NULL)
    {
        if(t->clanak.id == clanak_id)
        {
            if(last == NULL)
            {
                *prvi = t->sl;
                free(t);
                return;
            }
            else
            {
                last->sl = t->sl;
                free(t);
                return;
            }
        }
        last = t;
        t = t->sl;
    }
}

//ubacuje cvor na prvo mesto u listi
void ubaci_prvi(cvor **prvi, n_clanak clanak_x)
{
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->sl = *prvi;
    novi->clanak = clanak_x;
    *prvi = novi;
}

//ubacuje cvor na poslednje mesto u listi
void ubaci_poslednji(cvor **prvi, n_clanak clanak_x)
{
    cvor *t = *prvi;
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->sl = NULL;
    novi->clanak = clanak_x;
    if(t == NULL)
    {
        *prvi = novi;
        return;
    }
    while(t->sl != NULL)
    {
        t = t->sl;
    }
    t->sl = novi;
}

//ubacuje cvor u sortiranu listu tako da ostane sortirana
void ubaci_sortirano(cvor **prvi, n_clanak x)
{
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->clanak = x;
    cvor *t = *prvi, *last = NULL;

    while(t != NULL)
    {
        if(x.godina < t->clanak.godina || (x.godina == t->clanak.godina && strcmp(x.naslov,t->clanak.naslov) == -1))
        {
            break;
        }
        last = t;
        t = t->sl;
    }
    if(last == NULL)
    {
        novi->sl = *prvi;
        *prvi = novi;
        return;
    }
    last->sl = novi;
    novi->sl = t;
}

//Vrsi obradu tako sto pravi niz pokazivaca na pocetak liste za svaki casopis
//Pojedinacne liste naslova iz 1 casopisa sortira
cvor **obradi(cvor *prvi, int *n)
{
    int i = 0;
    cvor **p = (cvor**)malloc(10 * sizeof(cvor*));
    cvor *t = prvi;

    while(t != NULL)
    {
        if(!i && i % 10 == 0)
        {
            p = (cvor**)realloc(p,(i + 10) * sizeof(cvor*));
        }
        p[i] = NULL;
        cvor *q = t->sl;
        while(q != NULL)
        {
            if(strcmp(t->clanak.casopis, q->clanak.casopis) == 0)
            {
                ubaci_sortirano(&p[i],q->clanak);
                izbaci(&prvi,q->clanak.id);
            }
            q=q->sl;
        }
        ubaci_sortirano(&p[i],t->clanak);
        t = t->sl;
        i++;
    }
    *n = i;
    return p;
}