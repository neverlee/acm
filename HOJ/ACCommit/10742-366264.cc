#include <cstdio>
int main() 
{ 
    long long m,n,ii;
    long long S;
    scanf("%I64d %I64d",&m,&n);
    S=1;
    for(ii=m;ii<m+n;ii++)
        S*=ii;
    printf("%I64d",S);
    return 0;
}