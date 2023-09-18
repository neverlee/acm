#include <iostream>
using namespace std;

int main()
{
    long num;
    for(;;)
    {
        cin >>num;
        if(num==0)return 0;
        short k=0;
        long t=1;
        while((num&t)==0)
        {
            k++;
            num>>=1;
        }
        cout <<(t<<k) <<endl;
    }
}

