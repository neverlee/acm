#include <iostream>
using namespace std;

int coin,pirate,remain,temp;
int main()
{
    cin >>coin >>pirate;
    remain=coin;
    for(int i=0;i<pirate;i++)
    {
        temp=remain%pirate+remain/pirate;
        remain-=temp;
        cout <<temp;
        if(i!=pirate-1)cout <<" ";
    }
    cout <<endl <<remain <<endl;
}
