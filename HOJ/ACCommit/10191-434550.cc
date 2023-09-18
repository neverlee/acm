#include <cstdio>

typedef __int64 int64;

int64 f[21]={1,1};

int main() {
    for( int i=2; i<=20; ++i )
        for( int j=0; j<i; ++j )
            f[i] += f[j]*f[i-j-1];
    int n, t;
    scanf( "%d", &n );
    while( n-- ) {
        scanf( "%d", &t );
        printf( "%I64d\n", f[t] );
    }
}
