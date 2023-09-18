#include<iostream>
#include<string>
using namespace std;
int matrix[7][7];
int n;
void shift_matrix(int p)
{
    int temp = matrix[p][n - 1];
    for(int i = n - 1; i > 0; --i)
        matrix[p][i] = matrix[p][i - 1];
    matrix[p][0] = temp;
}
int main()
{
    int i, j;
    int ans;
    int max_temp;
    int temp;
    int curr[7];
    int p;
    while(cin >> n && n != -1)
    {
        ans = 10000000;
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                cin >> matrix[i][j];
        memset(curr, 0, sizeof(curr));
        while(true)
        {
            max_temp = -1000000;
            for(i = 0; i < n; ++i)
            {
                temp = 0;
                for(j = 0; j < n; ++j)
                    temp += matrix[j][i];
                if(temp > max_temp)
                    max_temp = temp;
            }
            if(max_temp < ans)
                ans = max_temp;
            p = 0;
            while(p < n && curr[p] == n - 1)
            {
                curr[p] = 0;
                shift_matrix(p);
                ++p;
            }
            if(p == n)
                break;
            ++curr[p];
            shift_matrix(p);
        }
        cout << ans << endl;
    }
    return 0;
}