#include <iostream>
#include <algorithm>
using namespace std;
int num,kn[200],total;

int main()
{
    while(cin >>num)
    {
        if(num==0)return 0;
        total=0;
        for(int i=0;i<num;i++)
        {cin >>kn[i];total+=kn[i];}
        if(num%2){cout <<"No" <<endl;continue;}
        if(total%(num/2)){cout <<"No" <<endl;continue;}
        total/=(num/2);
        sort(kn,kn+num);
        bool isright=1;
        for(int i=0;i<num/2;i++)
            if(kn[i]+kn[num-i-1]!=total)
            {isright=0;break;}
        if(isright)
            cout <<"Yes" <<endl;
        else
            cout <<"No" <<endl;
    }
}