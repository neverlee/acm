#include <cstdio>
int rect[101][101],n;
int dp[101][101][101],max;

void Dp()
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            dp[1][i][j]=rect[1][j]-rect[1][i];
            if(dp[1][i][j]>max)max=dp[1][i][j];
        }
    for(int i=2;i<=n;i++)
        for(int j=0;j<n;j++)
            for(int k=j+1;k<=n;k++)
            {
                dp[i][j][k]=rect[i][k]-rect[i][j]
                +(dp[i-1][j][k]<0?0:dp[i-1][j][k]);
                if(dp[i][j][k]>max)max=dp[i][j][k];
            }
}

int main()
{
    scanf("%ld",&n);
    int tn;max=0;
    for(int i=1;i<=n;i++)rect[i][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%ld",&tn);
            rect[i][j]=rect[i][j-1]+tn;
        }
    Dp();
    printf("%ld\n",max);
    return 0;
}