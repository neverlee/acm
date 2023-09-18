#include <iostream>
using namespace std;
int main()
{
    long long a,b,c,d,e;
    while(cin >>a >>b >>c >>d)
    {
        e=(a*(a-1)/2*b-d)/c;
        if(e)
            cout <<e <<endl;
        else
            cout <<a <<endl;
    }
    return 0;
}