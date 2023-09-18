#include <cstdio>
__int64 f[31] = { 1, 1 };

int main() {
    for( int i=2; i<=30; ++i ) {
        for( int j=0; j<i; ++j )
            f[i] += f[j]*f[i-1-j];
    }
    int n;
    while( scanf( "%d", &n ), n )
        printf( "%I64d\n", f[n] );
}