#include<stdio.h>
int main()
{
    int i,j,n;
    while(scanf("%d",&n)+1)
    {
        if(n==0)break;
        for(i=j=n;j--||(putchar(10),j=n-1,--i);printf("%-8d",((n-1)*3/2+i-j)    %n*n+((5*n-1)/2+i+j-n-n)%n+1));
    }
    return 0;
}