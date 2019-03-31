#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    long long time = 0, buyer_sum = 0, seller_sum = 0;

    scanf("%d", &n);

    while(n > 0)
    {
        time = 0;
        buyer_sum = 0;
        seller_sum = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);

            if(x > 0)
            {
                buyer_sum += x;
            }
            else
            {
                seller_sum += -x;
            }
            
            time += llabs(seller_sum - buyer_sum);
        }
        printf("%lld\n", time);
        scanf("%d", &n);
    }
       
}