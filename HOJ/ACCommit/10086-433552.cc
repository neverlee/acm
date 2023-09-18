#include<iostream>
#include<string>
using namespace std;
const int N = 101;
const int max_num = 0x7FFFFFFF;
int main()
{
    int a[N][N];
    int ans[N];
    memset(a, 0, sizeof(a));
    int i, j, k;
    for(i = 1; i < N; ++i)
        for(j = 1; j < N; ++j)
        {
            a[i][j] = max_num;
            for(k = 1; k <= i && k <= j; ++k)
            {
                if(a[i][j] > a[i-k][j] + a[k][j-k])
                    a[i][j] = a[i-k][j] + a[k][j-k];
                if(a[i][j] > a[i][j-k] + a[i-k][k])
                    a[i][j] = a[i][j-k] + a[i-k][k];
            }
            ++a[i][j];
            if(i == j)
            {
                ans[i] = max_num;
                for(k = 1; k < i; ++k)
                {
                    if(ans[i] > a[i-k][j] + a[k][j-k])
                        ans[i] = a[i-k][j] + a[k][j-k];
                    if(ans[i] > a[i][j-k] + a[i-k][k])
                        ans[i] = a[i][j-k] + a[i-k][k];
                }
            }
        }
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int t;
        scanf("%d", &t);
        printf("%d\n", ans[t]+1);
    }
    return 0;
}