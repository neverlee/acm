#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int ncase;
    cin >>ncase;
    long long num,k;
    for(int text=0;text<ncase;text++)
    {
        cin >>num;
        if(text!=0)cout <<" ";
        if(num<10)
        {
            if(num==1||num==2||num==4||num==7)
                cout <<"1";
            else
                cout <<"0";
            continue;
        }
        num=num*2-2;
        k=(long)sqrt((double)num);
        if((k+1)*(k+2)==num||k*(k+1)==num||k*(k-1)==num||(k-1)*(k-2)==num)
            cout <<"1";
        else
            cout <<"0";
    }
    cout <<endl;
    return 0;
}