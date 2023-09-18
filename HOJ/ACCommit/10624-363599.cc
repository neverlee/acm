#include <iostream>
using namespace std;
int main()
{
    int num;
    while(cin >>num)
    {
        num-=265716;
        cout <<9+(num%3);
        for(int i=1;i<10;i++)
        {
            num/=3;
            cout <<" " <<9+num%3;
        }
        cout <<endl;
    }
    return 0;
}
