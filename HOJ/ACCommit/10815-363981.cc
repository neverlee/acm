#include <iostream>
using namespace std;
int GetResult(int num)
{
    if(num==3)return 1;
    if(num<3)return 0;
    if(num%2)
        return GetResult(num/2)+GetResult(num/2+1);
    else
        return GetResult(num/2)*2;
}
int main()
{
    int knum;
    while(cin >>knum)        
        cout <<GetResult(knum) <<endl;
    return 0;
}