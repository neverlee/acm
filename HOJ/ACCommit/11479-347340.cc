#include <iostream>
#include "math.h"
using namespace std;

short prime[200]={2,3},np=2;
long num[200];short ptnum;
long key1,key2;
void getprime()
{
    short pi=2;
    for(int i=5;i<1000;i+=2)
    {
        int sqrtn = (int)sqrt((float)i);
        bool flag=true;
        for(int j=0;prime[j]<=sqrtn;j++)
            if(i%prime[j]==0)
            {
                flag=false;break;
            }
        if(flag==true)
        {
            prime[pi]=i;
            pi++;
        }
    }
    np=pi;
}

void getkey(long*key)
{
    int i;
    ptnum=0;
    for(i=0;i<np;i++)
    {
        if(*key%prime[i]==0)
        {
            num[ptnum]=prime[i];ptnum++;
            while(*key%prime[i]==0)
                *key/=prime[i];
        }
    }
    if((*key)>num[ptnum-1])
        num[ptnum]=*key;
    else
    {
        ptnum--;
    }
    for(i=0;i<ptnum;i++)
        num[ptnum]-=num[i];
    (*key)=num[ptnum];
}

int main()
{
    getprime();
    for(;;)
    {
        cin >>key1 >>key2;
        if(key1==0)
            break;
        else
        getkey(&key1);
        getkey(&key2);
        if(key1>key2)
            cout <<"a\n";
        else
            cout <<"b\n";
    }
    return 0;
}

