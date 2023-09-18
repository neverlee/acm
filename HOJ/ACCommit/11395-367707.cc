#include<cstdio>
#include<cmath>
const double eps = 1e-8;
double nm,ex,k;
int main()
{
    int ncase;
    scanf("%ld",&ncase);
    while(ncase--)
    {
        scanf("%lf%lf",&nm,&ex);
        k=ex*log10(nm)-(long)(ex*log10(nm)+eps);
        printf("%ld\n",(long)pow(10,k));
    }
    return 0;
}