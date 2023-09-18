#include <cstdio>

#define mod(a,b) (((a)%(b)+(b))%(b))

typedef __int64 int64;

int64 exgcd( int64 a, int64 b, int64 &x, int64 &y ) {
    if( b==0 ) { x=1; y=0; return a; }
    int64 t, d;
    d = exgcd( b, mod(a,b), x, y );
    t=x; x=y; y = t-(a/b)*y;
    return d;
}

void work( int64 a, int64 b, int64 n ) {
    int64 d, x, y;
    d = exgcd( a, b, x, y );
    if( d!=1 ) puts( "IMPOSSIBLE" );
    else printf( "%I64d\n", x>0?x:x+b );
}

int main() {
    int64 a, b;
    int T; scanf( "%d", &T );
    while( T-- ) {
        scanf( "%I64d%I64d", &a, &b );
        work( b, a, 1 );
    }
}

