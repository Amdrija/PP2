#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLEN 10005

struct cow
{
    int milk;
    int deadline;
};

int compare(const void  *x, const void *y)
{
    struct cow a = *(struct cow*)x;
    struct cow b = *(struct cow*)y;
    if(a.milk == b.milk)
        return a.deadline - b.deadline;

    return b.milk - a.milk;
}

int min(int a , int b)
{
    return a < b ? a : b;
}

int main()
{
    struct cow cows[MAXLEN];
    int n, milk = 0;
    bool milking[MAXLEN] = {0};

    printf("%d",sizeof(long));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &cows[i].milk, &cows[i].deadline);
    }

    qsort(cows,n,sizeof(struct cow),compare);

    for(int i = 0; i < n; i++)
    {
        for(int j = min(n, cows[i].deadline) - 1; j >= 0; j--)
        {
            if(!milking[j])
            {
                milking[j] = 1;
                milk += cows[i].milk;
                break;
            }
        }
    }

    printf("%d", milk);


    return 0;
}