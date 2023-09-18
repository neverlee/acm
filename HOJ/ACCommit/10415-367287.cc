#include <cstdio>
int num,total;
bool dp[50001];
int tn,max,min,k;
inline int asb(int x)
{return x<0?-x:x;}
void DP()
{
    for(int i=1;i<50001;i++)dp[i]=0;
    dp[0]=1;total=0;
    max=0;
    for(int i=0;i<num;i++)
    {
        scanf("%ld",&tn);total+=tn;
        for(int j=max;j>=0;j--)
            if(dp[j])
            {
                dp[j+tn]=1;
                max=j+tn>max?j+tn:max;
            }
    }
    min=4000;
    k=total/2+1;while(!dp[k]&&k<2600)k++;
    if(asb(total-2*k)<min)min=asb(total-2*k);
    k=total/2;while(!dp[k]&&k>=0)k--;
    if(asb(total-2*k)<min)min=asb(total-2*k);
    printf("%ld\n",min);
}

int main()
{
    while(scanf("%ld",&num)!=EOF)
        DP();
    return 0;
}