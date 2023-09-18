#include "stdio.h"
int main()
{
    int i,j,m,n,ncase,Mul,Div;
    double Answer;
    scanf("%d",&ncase);
    for(i=0;i<ncase;i++)
    {
        scanf("%d%d",&m,&n);
        Mul=0;Div=0;
        Answer=m;
        for(j=1;j<=n+1;j++)
        {
            if(j<=m)
                Answer*=j;
            if(j<=n-m)
                Answer/=j;
            if(j>=m+2)
                Answer*=j;
            if(j<=n && j>=n-m+1)
                Answer/=j;
        }
        printf("%.6lf\n",Answer);
    }
    return 0;
}