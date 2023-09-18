#include <iostream>
using namespace std;
const long long MOD = 1234567;
int num;

long long GetMod(long long n)
{
    if(n==1)return 2;
    long long kn=GetMod(n/2)%MOD;
    kn=(kn*kn)%MOD;
    if(n%2)
        return (kn*2)%MOD;
    else
        return kn;
}

int main()
{
    int ncase;cin >>ncase;
    for(int text=1;text<=ncase;text++)
    {
        cin >>num;
        if(num==1)
        {
            cout <<text <<". Sum = " <<1 <<endl;
            continue;
        }
        cout <<text <<". Sum = " <<(GetMod(num-1)+num+num-3)%MOD <<endl;
    }
    return 0;
}