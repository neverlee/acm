//10907 
#include <iostream>
using namespace std;
int main()
{
    short ncase;
    cin >>ncase;
    long a,b,c;
    for(int text=0;text<ncase;text++)
    {
        cin >>a >>b >>c;
        b-=c;
        if(a==b)cout <<"does not matter" <<endl;
        if(a>b)cout <<"do not advertise" <<endl;
        if(a<b)cout <<"advertise" <<endl;
    }
    return 0;
}