#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    long num,rec;
    cout <<"PERFECTION OUTPUT" <<endl;
    while(cin >>num)
    {
        if(!num){cout <<"END OF OUTPUT" <<endl;return 0;}
        rec=0;
        for(int i=1;i<=num/2;i++)
            if(!(num%i))rec+=i;
        cout <<setw(5) <<num;
        if(num==rec)cout <<"  PERFECT" <<endl;
        if(num<rec)cout <<"  ABUNDANT" <<endl;
        if(num>rec)cout <<"  DEFICIENT" <<endl;
    }
}