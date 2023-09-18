#include <iostream>
using namespace std;
int main()
{
    int ncase;
    cin >>ncase;
    int a,b,c,d;
    for(int text=0;text<ncase;text++)
    {
        cin >>a >>b >>c >>d;
        cout <<c-b+a <<endl;
    }
    return 0;
}