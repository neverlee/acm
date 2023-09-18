#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
int arr[MAXN], n;
void solve (){
    int i, ans = 0;
    for (i = 1; i <= n; )
        if ( arr[i]!=i ) {
            swap( arr[i], arr[arr[i]] );
            ++ans;
        }else ++i;
    printf ("%d\n", ans);
}
int main (){
    int T, i;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d", &n);
        for (i = 1; i <= n; i++)
            scanf ("%d", &arr[i]);
        solve ();
    }
    return 0;
}
