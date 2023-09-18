#include <iostream>
using namespace std;
long L,stone[101];
short S,T,M;
void init()
{
    cin >>L;
    cin >>S >>T >>M;
    stone[0]=0;
    for(short i=1;i<=M;i++)
        cin >>stone[i];
}

void dealsame()
{
    short most=0;
    for(short i=1;i<=M;i++)
        if(stone[i]%S==0)
            most++;
    cout <<most <<endl;
}

void sortstone()
{
    long t;
    for(int i=1;i<M;i++)
        for(int j=i+1;j<=M;j++)
            if(stone[i]>stone[j])
            {
                t=stone[i];stone[i]=stone[j];stone[j]=t;
            }
}

void dealstone()
{
    long SS=S*T;
    for(int i=0;i<M;i++)
    {
        long d=stone[i+1]-stone[i];
        if(d>(2*SS))
        {
            long n=d/SS - 1;
            for(int j=i+1;j<=M;j++)
                stone[j]-=(n*SS);
        }
    }
}

void dealdiff()
{
    sortstone();
    dealstone();
    short havefoot[20000]={1,0};
    bool isstone[20000]={0};
    for(int i=1;i<=M;i++)
        isstone[stone[i]]=true;
    for(int i=0;i<=stone[M];i++)
    {
        if(havefoot[i]>0)
        {
            for(int j=i+S;j<=i+T;j++)
            {
                short sn=0;
                if(isstone[j])
                    sn=1;
                if(havefoot[j]==0)
                    havefoot[j]=havefoot[i]+sn;
                else
                {
                    if(havefoot[i]+sn<havefoot[j])
                        havefoot[j]=havefoot[i]+sn;
                }
            }
        }
    }
    short min=200;
    for(int i=stone[M];i<=stone[M]+T;i++)
        if((havefoot[i]>0)&&(havefoot[i]<min))
            min=havefoot[i];
    cout <<min-1 <<endl;
}

int main()
{
    short mn;
    cin >>mn;
    for(int i=0;i<mn;i++)
    {
        init();
        if(S==T)
            dealsame();
        else
            dealdiff();
    }
    return 0;
}

