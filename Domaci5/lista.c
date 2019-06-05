#include "funkcije.h"



void dodaj(cvor **first, cvor **last, sub_title titl)
{
    cvor *novi = (cvor*)malloc(sizeof(cvor));
    novi->inf = titl;
    novi->last = *last;
    novi->next = NULL;

    if(*first == NULL)
    {
        *first = novi;
    }
    else
    {
        (*last)->next = novi;
    }
    *last = novi;
}

void pisi(cvor *first)
{
    while(first)
    {
        print_title(first->inf);
        first = first ->next;
    }
}

void brisi(cvor *first)
{
    cvor *t;
    while(first)
    {
        t = first;
        first = first->next;
        free(t->inf.text);
        free(t);
    }
}