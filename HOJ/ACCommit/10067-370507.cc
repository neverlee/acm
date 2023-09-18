#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10005;

int arr[MAXN], n;

void solve ()
{
    int i, ans = 0, j, k;
    for (i = 1; i <= n; i++)
        if (arr[i])
        {
            j = arr[i];
            arr[i] = 0;
            while (j != i)
            {
                k = arr[j];
                arr[j] = 0;
                j = k;
                ans++;
            }
        }
    printf ("%d\n", ans);
}
int main ()
{
    int T, i;
    scanf ("%d", &T);
    while (T--)
    {
        scanf ("%d", &n);
        for (i = 1; i <= n; i++)
        scanf ("%d", &arr[i]);
        solve ();
    }
    return 0;
}