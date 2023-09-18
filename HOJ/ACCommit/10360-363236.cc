#include <iostream>
using namespace std;
int main()
{
    int ncase;
    cin >>ncase;
    int a,b;
    for(int i=0;i<ncase;i++)
    {
        cin >>a >>b;
        if(a>=b)
            cout <<"MMM BRAINS" <<endl;
        else
            cout <<"NO BRAINS" <<endl;
    }
    return 0;
}