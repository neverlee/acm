#include <iostream>
using namespace std;

int main()
{
    int a,b;
    while(cin >>a >>b)
    {
        if(a<=0||b<=0||((a+b)&1)==0)
            cout <<a <<" " <<b <<endl;
        else
            cout <<b <<" " <<a <<endl;
    }
    return 0;
}