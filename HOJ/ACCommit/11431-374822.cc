#include <cstdio>
const long SIZE=16777217;
bool isPrime[SIZE]={1,1,0};

void SetPrime()
{
    int k;
    for(int i=3;i<4096;i+=2)
        if(!isPrime[i])
            for(int j=i*i;j<SIZE;j+=(i<<1))
                isPrime[j]=1;
}

int main()
{
    SetPrime();
    int num,total;
    while(scanf("%ld",&num)!=EOF)
    {
        total=0;
        for(int i=3;i<=num-i;i+=2)
            if(!isPrime[i]&&!isPrime[num-i])total++;
        printf("%ld\n",total);
    }
    return 0;
}