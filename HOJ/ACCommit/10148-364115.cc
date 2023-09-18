#include <iostream>
using namespace std;
const long SIZE=4194304;
bool isPrime[SIZE]={1,1,0};
int howMuch[SIZE]={0,0,1,2,2};
void SetPrime()
{
    int k;
    for(int i=4;i<=SIZE;i+=2)isPrime[i]=1;
    for(int i=3;i<2048;i+=2)
        if(!isPrime[i])
            for(int j=i;(k=i*j)<SIZE;j+=2)
                isPrime[k]=1;
    for(int i=5;i<SIZE;i+=2)
        howMuch[i]=howMuch[i+1]=howMuch[i-1]+1-isPrime[i];
}

int main()
{
    SetPrime();
    int a,b,re;
    while(cin >>a >>b)
    {
        re=howMuch[b]-howMuch[a]+(!isPrime[a]?1:0);
        cout <<re <<endl;
    }
    return 0;
}