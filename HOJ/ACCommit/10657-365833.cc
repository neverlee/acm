#include <cstdio>
#include <cmath>
int main()
{
    long num,tn;long long one,two;
    while(scanf("%ld",&num))
    {
        if(!num)return 0;
        if(num==2){printf("1 2\n");continue;}
        two=5;one=(long long)num*(num+1)/2;
        for(int i=3;i<=num;i++)
        {
            scanf("%ld",&tn);
            one-=tn;
            two+=(long long)i*i-(long long)tn*tn;
        }
        long long k=(long long)sqrt((double)(2*two-one*one));
        printf("%I64d %I64d\n",(one-k)/2,(one+k)/2);
    }
}