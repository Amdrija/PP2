#include <stdio.h>
#define MAXLEN 10000


int main()
{
    int a[MAXLEN], n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        int num_younger = -1;
        for(int j = i + 1; j < n; j++)
        {
            num_younger += (int)(a[i] > a[j]);
        }
        printf("%d ",num_younger);
    }
    printf("%d",-1);

    return 0;
}