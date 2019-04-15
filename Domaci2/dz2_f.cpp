#include <stdio.h>
#include <algorithm>
#include <string.h>

#define infinity 1000000000

using namespace std;

int n, a[210], dp[210][210][210];

int minimal(int last_white, int last_black, int index) 
{
    //vec smo izracunali minimalnu vrednost za datu trojku
    if (dp[last_white][last_black][index] != -1) 
        return dp[last_white][last_black][index];
    if (index == n) 
        return 0;

    //ako je trenutni element manji od poslednjeg belog, onda izracunamo
    //minimalan broj elemenata koje treba ofarbati ako ga ofarbamo u belo
    if (a[index] < a[last_white]) 
    {
        dp[last_white][last_black][index] = minimal(index, last_black, index + 1);
    }


    if (a[index] > a[last_black]) 
    {
        //ako je trenutni element veci od poslednjeg crnog i dosad nismo nasli
        //minimalan broj ofarbanih kuglica, onda izracunamo koji bi bio minimalan
        //broj ako ga ofarbamo u crno
        //a ako smo izracunali dp, onda uzmemo minimum dosad izracunatog i ako 
        //dati element ofarbamo u belo
        if (dp[last_white][last_black][index] == -1)
            dp[last_white][last_black][index] = minimal(last_white, index, index + 1);
        else
            dp[last_white][last_black][index] = min(minimal(last_white, index, index + 1), dp[last_white][last_black][index]);
    }

    //slucaj kada ne farbamo element
    //ako do sad nismo uspeli da nadjemo dp, onda ovaj element mora da ostane neofarban
    //a ako jesmo, onda uzmemo minimum dosad izracunatog dp i ako 1 + minimalan broj kuglica
    //ako ne ofarbamo element
    if (dp[last_white][last_black][index] == -1)
        dp[last_white][last_black][index] = 1 + minimal(last_white, last_black, index + 1);
    else
        dp[last_white][last_black][index] = min(1 + minimal(last_white, last_black, index + 1), dp[last_white][last_black][index]);

    return dp[last_white][last_black][index];
}

int main() 
{
    a[200] = infinity;
    a[201] = -infinity;


    scanf("%d", &n);
    while (n != -1) 
    {
        for (int i = 0; i < n; ++i) 
        {
            scanf("%d", &a[i]);
        }
        memset(dp, -1, sizeof dp);

        printf("%d\n", minimal(200, 201, 0));
        scanf("%d",&n);
    }
    
    return 0;
}


