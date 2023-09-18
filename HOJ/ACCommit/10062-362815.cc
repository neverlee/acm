#include <iostream>
using namespace std;
int main()
{
    long num,result,k,wei;
    while(cin >>num)
    {
        if(!num)return 0;
        cout <<num <<": ";
        result=0;wei=1;
        while(num>0)
        {
            k=num%10;num/=10;
            if(k>4)k--;
            result+=(k*wei);
            wei*=9;
        }
        cout <<result <<endl;
    }
}