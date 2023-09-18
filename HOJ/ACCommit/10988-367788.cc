#include<cstdio>
#include<cmath>
long long a,t,k,d;
int main()
{
    while(scanf("%I64d",&k)!=EOF)
    {
        if(!k)return 0;if(k%4)continue;
        t=k/4;
        d=(long long)sqrt((double)t);
        while(d*d>=t)--d;
        for(;;d--)
        {
            if(t%d==0)
            {
                t/=d;
                a=t+d;t-=d;
                printf("%I64d - %I64d = %I64d\n",a*a,t*t,k);
                break;
            }
        }
    }
    return 0;
}