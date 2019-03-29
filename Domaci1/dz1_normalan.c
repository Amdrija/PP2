#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define MAX_BR_EL 100000000
void make(int *niz, int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {   
        niz[i] = rand() % 100000;
    }
}


void ucitaj(int *niz, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&niz[i]);
    }
}

void ispisi(int *niz, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d",niz[i]);
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}
void vodje(int *niz, int n)
{
    int maximum; //i-ti element niza sadrzi maximum elemenata desno od njega

    maximum = niz[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        maximum = max(maximum, niz[i + 1]);
        //Ako je trenutni element veci od max svih elemenata desno od njega onda je vodja
        if(niz[i] > maximum)
        {
            //printf("%d , ",niz[i]);
        }
    }

}

void neoptimizovano(int *niz, int n)
{
    bool jes_vodja = true;
    for(int i = 0; i < n - 1 ; i++)
    {
        jes_vodja = true;
        for(int j = i + 1; j < n; j ++)
        {
            if(niz[i] <= niz[j])
            {
                jes_vodja = false;
                //break;
            }
        }
        if(jes_vodja);
            //printf("%d, ", niz[i]);
    }
}
int main()
{
    int n; 

    scanf("%d",&n);

    int niz[n];
    while(n > 0)
    {
        if(n > MAX_BR_EL)
        {
            printf("Broj elemenata u nizu mora biti manji od 100\n");
        }
        else
        {
            make(niz,n);
            time_t first = time(NULL);
            vodje(niz,n);
            time_t last = time(NULL);
            printf("%lf \n",difftime(last, first));
            first = time(NULL);
            neoptimizovano(niz, n);
            last = time(NULL);
            printf("%lf \n",difftime(last, first));
        }
        scanf("%d",&n);
    }

    return 0;
}