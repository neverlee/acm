#include <cstdio>
const long SIZE=16777217;
bool isPrime[SIZE]={1,1,0};

void SetPrime(){
    for(int i=3;i<4096;i+=2)
        if(!isPrime[i])
            for(int j=i*i;j<SIZE;j+=(i<<1))
                isPrime[j]=1;
    for(int i=3;i<16777217;i+=2)isPrime[i]=!isPrime[i];
}

int main(){
    SetPrime();
    int num,total,k;
    while(scanf("%ld",&num)!=EOF)    {
        k=num>>1;
        total=0;
        for(int i=3;i<=k;i+=2)
            if(isPrime[i]&&isPrime[num-i])++total;
        printf("%ld\n",total);
    }
    return 0;
}