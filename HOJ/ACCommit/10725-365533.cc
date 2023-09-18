#include <cstdio>
const long SIZE=1000001;
bool isPrime[SIZE]={1,1,0};

void SetPrime()
{
    int k;
    for(int i=3;i<1000;i+=2)
        if(!isPrime[i])
            for(int j=i;(k=i*j)<SIZE;j+=2)
                isPrime[k]=1;
}

int main()
{
    SetPrime();
    int num;bool isFalse;
    while(scanf("%ld",&num))
    {
        if(num==0)return 0;
        isFalse=1;
        for(int i=3;i<=num-i;i+=2)
            if(!isPrime[i]&&!isPrime[num-i])
            {
                printf("%ld = %ld + %ld\n",num,i,num-i);
                isFalse=0;break;
            }
        if(isFalse)printf("Goldbach\'s conjecture is wrong.\n");
    }
    return 0;
}