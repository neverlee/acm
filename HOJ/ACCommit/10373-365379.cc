#include <iostream>
using namespace std;

int main()
{
    int store=0,buy,have=0;
    for(int i=1;i<=12;i++)
    {
        have+=300;
        cin >>buy;
        have-=buy;
        if(have<0)
        {cout <<-i <<endl;return 0;}
        else
        {
            store+=have/100;
            have%=100;
        }
    }
    cout <<store*120+have <<endl;
    return 0;
}