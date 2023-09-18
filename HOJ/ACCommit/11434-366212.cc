#include <cstdio>
int main()
{
    int ncase,m,n;
    scanf("%ld",&ncase);
    for(int text=0;text<ncase;text++)
    {
        scanf("%ld%ld",&m,&n);
        printf("%ld\n",4*m+6*n+6);
    }
    return 0;
}