#include<cstdio>
#include<cmath>

int prime[1250]={2,3,5},numPrime=3;
int base[4]={1,3,7,9};
int rect[8][100000]={4,2,3,5,7};

inline bool isPrime(int num)
{
    for(int i=0;prime[i]<=(int)sqrt((double)num);i++)
        if(num%prime[i]==0)return 0;
    return 1;
}

void SetPrime()
{
    for(int i=7;i<10000;i+=2)
        if(isPrime(i)){prime[numPrime]=i;++numPrime;}
}

void SetRect()
{
    int temp;
    for(int i=1;i<8;i++)rect[i][0]=0;
    for(int i=1;i<8;i++)
        for(int j=1;j<=rect[i-1][0];j++)
            for(int k=0;k<4;k++)
            {
                temp=rect[i-1][j]*10+base[k];
                if(isPrime(temp))
                    rect[i][++rect[i][0]]=temp;
            }
}

int main()
{
    int num;
    SetPrime();
    SetRect();
    scanf("%ld",&num);
    for(int i=1;i<=rect[num-1][0];i++)
        printf("%ld\n",rect[num-1][i]);
    return 0;
}