#include <cstdio>
int main()
{
    int wei10,wei12,wei16;
    int k;
    for(int i=2992;i<10000;i++)
    {
        wei10=wei12=wei16=0;
        k=i;while(k>0){wei10+=k%10;k/=10;}
        k=i;while(k>0){wei12+=k%12;k/=12;}
        k=i;while(k>0){wei16+=k%16;k/=16;}
        if(wei10==wei12&&wei12==wei16)
            printf("%d\n",i);
    }
    return 0;
}
