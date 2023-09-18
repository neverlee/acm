#include <cstdio>
#include <cstring>
const int N = 250010;
int amount, lmt, t;
__int64 f[N];
int main() {
    scanf( "%d%d", &amount, &lmt );
    f[0] = 1;
    while( amount-- ) {
        scanf( "%d", &t );
        for( int i=t; i<=lmt; ++i )
            f[i] += f[i-t];
    }
    printf( "%I64d", f[lmt] );
}
