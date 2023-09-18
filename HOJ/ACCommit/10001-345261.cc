#include <iostream>
using namespace std;

short n;
short number[1001];
short dpc[1001];

void init()
{
    cin >>n;
    for(int i=1;i<=n;i++)
        cin >>number[i];
    number[0]=0;
}

void dp()
{
    for(int i=1;i<=n;i++)
        dpc[i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(number[j]<number[i])
            {
                if(dpc[i]<dpc[j]+1)
                    dpc[i]=dpc[j]+1;
                
            }
        }
    }
}

int main()
{
    init();
    dp();
    short max=0;
    for(int i=1;i<=n;i++)
        if(dpc[i]>max)
            max=dpc[i];
    cout << max;
    return 0;
}

