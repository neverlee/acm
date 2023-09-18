#include <iostream>
using namespace std;
short num[1001];
short total;
int main()
{
    cin >>total;
    for(int i=0;i<total;i++)cin >>num[i];
    short dp[1001]={0};
    for(int i=0;i<total;i++)dp[i]=1;
    for(int i=1;i<total;i++)
        for(int j=0;j<i;j++)
        {
            if(num[i]>num[j])
                dp[i]=dp[i]>(dp[j]+1)?dp[i]:(dp[j]+1);
        }
    short max=0;
    for(int i=0;i<total;i++)
        if(dp[i]>max)max=dp[i];
    cout <<max <<endl;
    return 0;
}