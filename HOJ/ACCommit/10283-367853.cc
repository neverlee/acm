#include<iostream>
using namespace std;
long long m;
int k;

int main()
{
    int t;cin >>t;
    while(t--)
    {
        cin >>k;m=1LL;
        for(int i=0;i<k-2;i++)
            m*=k;
        cout <<m <<endl;
    }
    return 0;
}