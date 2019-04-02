#include <stdio.h>

#define MAXLEN 10005
int main()
{
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        
        if(n > 9)
        {
            long long encode = 0, pow10 = 1;
            for(int j = 9; j >= 2 && n > 1; j--)
            {
                while(n % j == 0)
                {
                    encode += j * pow10;
                    pow10 *= 10;
                    n /= j;
                }

            }
            if(n != 1)
            {
                printf("%d\n", -1);
            }
            else
            {
                printf("%lld\n", encode);
            }
        }
        else
        {
            printf("%d\n",n);
        }
        
        
    }
}