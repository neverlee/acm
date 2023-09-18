#include <iostream>
using namespace std;
unsigned long fib[100]={1,2};
unsigned long long num;

void SetFib()
{
    int i;
    for(i=2;i<46;i++)
        fib[i]=fib[i-1]+fib[i-2];
}

void GetAnswer()
{
    int wei=0;
    while(num>=fib[wei])wei++;
    for(int i=wei-1;i>=0;i--)
    {    if(num>=fib[i])
        {
            cout <<1;num-=fib[i];
        }
        else cout <<0;
    }
    cout <<endl;
}

int main()
{
    SetFib();
    while(cin >>num)
    {
        if(num<2){cout <<num <<endl;continue;}
        GetAnswer();
    }
}