#include <stdio.h>

int main()
{
    int n,m,a,d,min=10000000,t;
    double temp;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
         while(m--)
         {
             scanf("%d %d",&a,&d);
             temp=n*(double)d/(d+a);
             t=(int)temp+1;
             if(min>t*a-(n-t)*d)
                 min=t*a-(n-t)*d;
         }
         printf("%d\n",min);
         min=10000000;
    }
    return 0;
}