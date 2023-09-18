#include <iostream>
using namespace std;
int main()
{
    short ncase;
    cin >>ncase;
    long long a,b,c,d;
    for(int i=0;i<ncase;i++)
    {
        cin >>a >>b >>c >>d;
        if((a+b*d)>b*c)
            cout <<"do not parallelize" <<endl;
        if((a+b*d)<b*c)
            cout <<"parallelize" <<endl;
        if((a+b*d)==b*c)
            cout <<"does not matter" <<endl;
    }
    return 0;
}