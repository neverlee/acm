#include <iostream>
using namespace std;
int main()
{
    long long num[50]={0,1};
    for(int i=2;i<46;i++)
        num[i]=num[i-1]+num[i-2];
    short n,k;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>k;
        cout <<num[k] <<endl;
    }
    return 0;
}
