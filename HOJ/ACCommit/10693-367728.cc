#include<cstdio>
#include<algorithm>
using namespace std;
unsigned n2[31],n3[31];
unsigned freNum[400],have=0;
unsigned num;unsigned k;
void SetData()
{
    n2[0]=n3[0]=1;
    for(int i=0;i<30;i++)
    {n2[i+1]=n2[i]*2;n3[i+1]=n3[i]*3;}
    for(int i=0;i<=20;i++)
        for(int j=0;j<=30;j++)
        {
            k=n3[i]*n2[j]-1;
            if(k>=(1<<30))break;
            freNum[have++]=k;
        }
    sort(freNum,freNum+have);
}
bool isFre(unsigned num)
{
    for(int i=1;i<have;i++)
        if(num==freNum[i])return 1;
    return 0;
}

int main()
{
    SetData();
    while(scanf("%ld",&num)!=EOF)
    {
        if(isFre(num))printf("YES!\n");
        else printf("NO!\n");
    }
    return 0;
}