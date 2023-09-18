#include <iostream>
using namespace std;
int main()
{
    long long a,b;long long re;
    while(1)
    {
        cin >>a >>b;
        if(a==0)break;
        for(long long i=2;((i<=a)&&(i<=b));i++)
            while((a%i==0)&&(b%i==0))
            {
                a/=i;b/=i;
            }
        re=a*b;
        if(a==b){cout <<"1" <<endl;continue;}
        cout <<re <<endl;
    }
    return 0;
}