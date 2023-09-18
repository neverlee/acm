#include <iostream>
using namespace std;
const int Mod=10000;
class BigNumber
{
    private:
        long num[200];
        int wei;
    public:
        void SetNum(int n);
        void InWei();
        friend BigNumber operator*(BigNumber my, int n);
        void PutOut();
};

void BigNumber::SetNum(int n)
{for(int i=1;i<200;i++)num[i]=0;num[0]=n;wei=1;}

void BigNumber::InWei()
{
    for(int i=0;i<wei;i++)
    {num[i+1]+=num[i]/Mod;num[i]%=Mod;}
    while(num[wei]>=Mod)
    {num[wei+1]=num[wei]/Mod;num[wei]%Mod;wei++;}
    while(num[wei])wei++;
}

BigNumber operator*(BigNumber my, int n)
{
    BigNumber result;result.SetNum(0);
    for(int i=0;i<my.wei;i++)
        result.num[i]=my.num[i]*n;
    result.wei=my.wei;
    result.InWei();
    return result;
}

void BigNumber::PutOut()
{
    printf("%ld",num[wei-1]);
    for(int i=wei-2;i>=0;i--)
        printf("%04ld",num[i]);
    printf("\n");
}

int main()
{
    BigNumber fact[101];
    fact[0].SetNum(1);fact[1].SetNum(1);
    for(int i=2;i<=100;i++)
        fact[i]=fact[i-1]*i;
    int num;
    while(cin >>num)
    {
        fact[num].PutOut();
    }
    return 0;
}