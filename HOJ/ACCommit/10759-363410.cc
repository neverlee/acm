#include <iostream>
using namespace std;
int main()
{
    int total,num[100],max,k,i;
    while(cin >>total)
    {
        if(total==0)return 0;
        max=k=0;
        bool iszero=0;
        for(i=0;i<total;i++)
        {
            cin >>num[i];
            if(num[i]>max)max=num[i];
            if(num[i]==0)iszero=1;
        }
        if(iszero){cout <<0 <<endl;continue;}
        while(1)
        {
            k+=max;
            for(i=0;i<total;i++)
                if(k%num[i])break;
            if(i==total)break;
        }
        cout <<k <<endl;
    }
}