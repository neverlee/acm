#include <iostream>
using namespace std;
int ncase,num1,num2,num3,mn;

void Setmn(int tn)
{
    while(tn>0)
    {
        if(tn%10>mn)
            mn=tn%10;
        tn/=10;
    }
}

int BaseNum(int num, int base)
{
    int k=1,result=0;
    while(num>0)
    {
        result+=(k*(num%10));
        num/=10;k*=base;
    }
    return result;
}
int main()
{
    cin >>ncase;
    for(int text=0;text<ncase;text++)
    {
        cin >>num1 >>num2 >>num3;
        mn=0;
        Setmn(num1);Setmn(num2);Setmn(num3);
        if(mn==0){cout <<"2\n";continue;}
        bool ishave=1;
        for(int i=mn+1;i<=16;i++)
            if(BaseNum(num1,i)*BaseNum(num2,i)==BaseNum(num3,i))
            {
                cout <<i <<endl;
                ishave=0;break;
            }
        if(ishave)
            cout <<0 <<endl;
    }
    return 0;
}