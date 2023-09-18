#include <iostream>
using namespace std;

int main()
{
    long result[21]={0,1,2,4};
    for(int i=4;i<21;i++)
        result[i]=result[i-1]+result[i-2]+result[i-3];
    short ncase,n;
    cin >>ncase;
    for(int i=0;i<ncase;i++)
    {
        cin >>n;
        cout <<result[n] <<endl;
    }
    return 0;    
}