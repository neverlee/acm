#include <iostream>
using namespace std;
int main()
{
    unsigned long long a,b;
    while(cin >>a)
    {
        if(a==0){cout <<1 <<endl;continue;}
        b=a*a-a+2;
        cout <<b <<endl;
    }
    return 0;
}