#include <iostream>
using namespace std;
int main()
{
    cout <<"Gnomes:" <<endl;
    long n,a,b,c;
    cin >>n;
    for(long i=0;i<n;i++)
    {
        cin >>a >>b >>c;
        if((a>b&&b>c)||(a<b&&b<c))
            cout <<"Ordered" <<endl;
        else
            cout <<"Unordered" <<endl;
    }
    return 0;
}