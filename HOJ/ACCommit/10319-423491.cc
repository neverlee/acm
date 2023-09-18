#include<iostream>
#include<string>
using namespace std;
const int N = 1001;
const int max_num = 0x7FFFFFFF;
int num[N];
int f[N][N];
int sub[N][N];
int sum[N][N];
int main()
{
    int n;
    int temp, min_value;
    int index;
    scanf("%d", &n);
    int i, j, k;
    for(i = 1; i <= n; ++i)
        scanf("%d", num+i);
    sort(num+1, num + n+1);
    for(i = 1; i <= n; ++i)
    {
        sum[i][i-1] = 0;
        for(j = i; j <= n; ++j)
        {
            sum[i][j] = sum[i][j-1] + num[j];
        }
    }
    for(i = 1; i <= n; ++i)
    {
        f[1][i] = num[i];
        sub[1][i] = i;
    }
    for(i = 2; i <= n; ++i)
        for(j = i; j <= n; ++j)
        {
            min_value = max_num;
            for(k = sub[i-1][j-1]; k <= sub[i-1][j]; ++k)
            {
                temp = sum[j-i+1][j];
                if(k+1 <= j)
                    temp += f[j-k][j];
                if(k-1 >= j - i + 1)
                    temp += f[k-j+i-1][k-1];
                if(min_value > temp)
                {
                    min_value = temp;
                    index = k;
                }
            }
            f[i][j] = min_value;
            sub[i][j] = index;
        }
    printf("%d\n", f[n][n]);
    return 0;
}