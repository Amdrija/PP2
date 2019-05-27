#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"

char *ucitaj_string()
{
    char c, *s;
    s = (char*)malloc(30 * sizeof(char));
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        if(i != 0 && i % 30)
        {
            s = (char*)realloc(s,(i + 30) * sizeof(char));
        }
        s[i++] = c;
    }
    s[i++] = '\0';
    s = (char*)realloc(s, i * sizeof(char));
    return s;
}

n_clanak ucitaj_clanak()
{
    n_clanak novi;
    char line[MAX_DUZINA_LINIJE];
    fgets(line,MAX_DUZINA_LINIJE,stdin);
    sscanf(line,"%d",&novi.id);

    novi.naslov = ucitaj_string();
    novi.casopis = ucitaj_string();
    
    fgets(line,MAX_DUZINA_LINIJE,stdin);
    sscanf(line, "%d", &novi.godina);

    return novi;
}

void ucitaj(cvor **prvi, int n)
{
    cvor *novi, *t;
    novi = (cvor*)malloc(sizeof(cvor));
    if(novi == NULL)
    {
        printf("Greska pri alokaciji memorije.\n");
        return;
    }
    novi->sl = NULL;
    novi->clanak = ucitaj_clanak();
    *prvi = novi;
    t = novi;
    for(int i = 1; i < n; i++)
    {
        novi = (cvor*)malloc(sizeof(cvor));
        if(novi == NULL)
        {
            printf("Greska pri alokaciji memorije.\n");
            return;
        }
        novi->sl = NULL;
        novi->clanak = ucitaj_clanak();
        t->sl = novi;
        t = novi;
    }
}