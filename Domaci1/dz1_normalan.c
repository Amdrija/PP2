#include <stdio.h>

#define MAX_BR_EL 100

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
    int desni_max[n]; //i-ti element niza sadrzi maximum elemenata desno od njega

    desni_max[n - 1] = niz[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        desni_max[i] = max(desni_max[i + 1], niz[i + 1]);

        //Ako je trenutni element veci od max svih elemenata desno od njega onda je vodja
        if(niz[i] > desni_max[i])
        {
            printf("%d , ",niz[i]);
        }
    }

}
int main()
{
    int n, niz[MAX_BR_EL];

    scanf("%d",&n);
    while(n > 0)
    {
        if(n > MAX_BR_EL)
        {
            printf("Broj elemenata u nizu mora biti manji od 100\n");
        }
        else
        {
            ucitaj(niz,n);
            vodje(niz,n);
            printf("\n");
        }
        scanf("%d",&n);
    }

    return 0;
}