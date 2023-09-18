#include <iostream>
using namespace std;
int main()
{
    short ncase;
    cin >>ncase;
    for(int i=0;i<ncase;i++)
    {
        long num,eat,re;
        cin >>num >>eat;
        if(num%eat)re=1;
        else re=0;
        re+=(num/eat);
        cout <<re <<endl;
    }
    return 0;
}