#include <cstdio>
int main()
{
    short ncase;
    scanf("%d",&ncase);
    long temp,num;
    for(int i=0;i<ncase;i++)
    {
        long k=1<<23,num=0;
        for(int j=0;j<24;j++)
        {
            scanf("%1ld",&temp);
            num+=(temp*k);k>>=1;
        }
        printf("%ld\n",num);
    }
    return 0;
}