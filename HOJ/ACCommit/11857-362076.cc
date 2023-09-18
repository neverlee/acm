#include <iostream>
using namespace std;

int main()
{
    long num,i,k;
    while(cin >>num)
    {
        for(i=1;(k=i*i)<=num;i++)
            cout <<k <<" ";
        cout <<endl;
    }
    return 0;
}