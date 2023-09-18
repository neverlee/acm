#include <iostream>
using namespace std;
int main()
{
    long num[10001]={1,2};
    for(int i=2;i<=10000;i++)
        num[i]=(num[i-1]+num[i-2])%10000007;
    short n;
    while(cin >>n)
    {
        if(n==-1)return 0;
        cout <<num[n] <<endl;
    }
}