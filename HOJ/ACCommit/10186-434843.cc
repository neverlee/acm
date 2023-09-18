#include <cstdio>
#include <cstring>

const int N = 101;
int nb, cap, lmt;
__int64 fa[N], fb[N];
int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d%d%d", &nb, &cap, &lmt );
        if( lmt==0 ) {
            puts( "0" );
            continue;
        }
        memset( fa, 0, sizeof(fa) );
        memset( fb, 0, sizeof(fb) );
        for( int i=0; i<=cap; ++i ) fa[i] = 1;
        for( int k=1; k<nb; ++k ) {
            for( int i=0; i<=lmt; ++i ) {
                fb[i] = 0;
                for( int j=0; j<=cap&&i-j>=0; ++j )
                    fb[i] += fa[i-j];
            }
            memcpy( fa, fb, sizeof(fb) );
        }
        printf( "%I64d\n", fa[lmt] );
    }
}