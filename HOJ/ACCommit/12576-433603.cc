#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 40010;
int x[N], y[N];
int xl, yl, n, t;
int main() {
    scanf( "%d%d%d", &xl, &yl, &n );
    for( int i=0; i<n; ++i )
        scanf( "%d%d", x+i, y+i );
    x[n] = y[n] = 0; ++n;
    x[n] = xl+1; y[n] = yl+1;
    sort( x, x+n ); sort( y, y+n );
    xl = yl = 1;
    for( int i=0; i<n; ++i ) {
        t = x[i+1]-x[i];
        xl = t>xl?t:xl;
        t = y[i+1]-y[i];
        yl = t>yl?t:yl;
    }
    printf( "%d", (xl-1)*(yl-1) );
}
