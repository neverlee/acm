#include <stdio.h>

int main()
{
    __int64 i,n,m,l,sum,lab;
    while (scanf("%I64d%I64d",&n,&m)) {
        if (n==0)
            return 0;
        sum=1;
        for (i=1; i<=m; i++) 
            sum=sum*(n-m+i)/i;
        printf("%I64d things taken %I64d at a time is %I64d exactly.\n",n,m,sum);
    }
    return 0;
}
