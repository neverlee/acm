#include <iostream>
using namespace std;

int main()
{
    long n,k,total;
    while(cin >>n >>k)
    {
        total=0;
        for(;n>k;)
        {
            long s;
            s=n/k;
            total+=s*k;
            n=n%k+s;
        }
        if(n==k)total++;
        total+=n;
        cout <<total <<endl;
    }
    return 0;
}