#include <stdio.h>
#include <stdlib.h>
#include "funkcije.h"
int main()
{
    cvor *prvi = NULL;
    cvor **p;
    int n, m, state = 1, id;
    char line[MAX_DUZINA_LINIJE];

    while(state)
    {
    printf("Unesite operaciju:\n\
            1. Unos liste clanaka\n\
            2. Brisanje liste clanaka\n\
            3. Ubacivanje clanka na pocetak liste\n\
            4. Ubacivanje clanka na kraj liste\n\
            5. Izbacivanje clanka odredjenog ID iz liste\n\
            6. Ispisivanje liste clanaka\n\
            7. Obrada liste clanaka\n\
            0. Izlaz iz programa\n");

    fgets(line, MAX_DUZINA_LINIJE, stdin);
    sscanf(line, "%d", &state); 

    switch (state)
    {
    case 0: printf("Izlazak iz programa.\n"); 
            break;
    case 1: printf("Unesite broj clanaka.\n");
            fgets(line, MAX_DUZINA_LINIJE, stdin);
            sscanf(line, "%d", &n);
            ucitaj(&prvi,n);
            break;
    case 2: brisi(prvi); 
            break;
    case 3: printf("Unesite clanak koji zelite da unesete na pocetak liste.\n");
            ubaci_prvi(&prvi, ucitaj_clanak());
            break;
    case 4: printf("Unesite clanak koji zelite da unesete na kraj liste.\n");
            ubaci_poslednji(&prvi, ucitaj_clanak());
            break;
    case 5: printf("Unesite ID clanka koji zelite da izbacite.\n");
            fgets(line, MAX_DUZINA_LINIJE, stdin);
            sscanf(line, "%d", &id);
            izbaci(&prvi, id);
            break;
    case 6: pisi(prvi);
            break;
    case 7: p = obradi(prvi,&m);
            printf("%d\n",m);
            for(int i = 0; i < m; i++)
            {
                pisi(p[i]);
            }
            for(int i = 0; i < m; i++)
            {
                    brisi(p[i]);
            }
            free(p);
            break;
    
    default:
            printf("Uneli ste nepostojecu operaciju.\n");
            break;
    }      
    
    }

    //Dealociranje memorije
    for(int i = 0; i < m; i++)
    {
        brisi(p[i]);
    }
    free(p);
    brisi(prvi);
    return 0;
}