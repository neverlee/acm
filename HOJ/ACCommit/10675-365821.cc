#include <cstdio>

int main()
{
    int ncase,num,a,b,c,d;
    scanf("%ld",&ncase);
    for(int text=0;text<ncase;text++)
    {
        scanf("%ld",&num);
        a=num/25;num%=25;
        b=num/10;num%=10;
        c=num/5;num%=5;
        d=num;
        printf("%ld %ld QUARTER(S), %ld DIME(S), %ld NICKEL(S), %ld PENNY(S)\n",text+1,a,b,c,d);
    }
    return 0;
}