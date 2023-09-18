#include <iostream>
using namespace std;

long long fh[60]={0,1};
long long gh[60]={0,1,0,1};
int main()
{
    short n;
    for(int i=4;i<=57;i++)
        gh[i]=gh[i-1]+gh[i-3];
    for(int i=2;i<=57;i++)
        fh[i]=fh[i-1]+gh[i-1];
    while(cin >>n)
        cout <<fh[n] <<endl;
    return 0;
}