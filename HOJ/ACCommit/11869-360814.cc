#include <iostream>
using namespace std;
int main()
{
    short num;
    while(cin >>num)
    {
        if(!num)return 0;
        short a,b;
        cin >>a;b=a;
        for(int i=1;i<num;i++)
        {
            cin >>b;
            if(b==a)continue;
            cout <<a <<" ";a=b;
        }
        cout <<b <<" $" <<endl;
    }
}