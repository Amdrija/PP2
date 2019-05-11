#include <stdio.h>
#include <iostream>

using namespace std;
int a[10010],dp[10010],n;

bool nzd_veci_1(int a, int b)
{

    // a je veci
    for(int i = 2; i * i <= a; i++)
    {
        if(a % i == 0 && b % i == 0)
            return true;
    
    }

    return false;
}

int result(int index)
{
    if(index == -1)
        return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i = 1; i < n; i++)
    {
        
    }


    
    return 0;
}