#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    short x1,y1,x2,y2;
    while(cin >>x1 >>y1 >>x2 >>y2)
    {
        if(!x1)return 0;
        if(x1==x2&&y1==y2){cout <<0 <<endl;continue;}
        if((abs(x2-x1)==abs(y2-y1))||(x1==x2)||(y1==y2))cout <<1 <<endl;
        else cout <<2 <<endl;
    }
}