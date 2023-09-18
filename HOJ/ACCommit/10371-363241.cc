#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >>num;
    int high[100];
    int dpl[100],dpr[100];
    for(int i=0;i<num;i++)
    {cin >>high[i];dpl[i]=dpr[i]=1;}
    for(int i=1;i<num;i++)
        for(int j=0;j<i;j++)
            if(high[i]>high[j]&&dpl[j]+1>dpl[i])
                dpl[i]=dpl[j]+1;
    for(int i=num-2;i>=0;i--)
        for(int j=num-1;j>i;j--)
            if(high[i]>high[j]&&dpr[j]+1>dpr[i])
                dpr[i]=dpr[j]+1;
    int m=0;
    for(int i=0;i<num;i++)
        if(m<dpl[i]+dpr[i]-1)m=dpl[i]+dpr[i]-1;
    cout <<num-m <<endl;
    return 0;
}
