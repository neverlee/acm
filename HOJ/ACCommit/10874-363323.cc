#include <iostream>
using namespace std;

int main()
{
    double a,b,c;int year;
    while(cin >>a >>b >>c)
    {
        b=(100.0+b)/100.0;
        year=0;
        while((a*=b)<c)year++;
        cout <<year+1 <<endl;
    }
}