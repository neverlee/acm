#include <cstdio>

#define mod(a,b) (((a)%(b)+(b))%(b))
typedef __int64 int8;

int8 ext_euclid( int8 a, int8 b, int8 &x, int8 &y ) {
    int8 t, d;
    if( b==0 ) { x=1; y=0; return a; }
    d = ext_euclid( b, mod(a,b), x, y );
    t=x; x=y; y=t-a/b*x;
    return d;
}

void solver( int8 a, int8 b, int8 n ) {
    int8 d, x, y;
    d = ext_euclid( a, n, x, y );
    if( mod(b,d)>0 ) puts("FOREVER");
    else {
        printf( "%I64d\n", mod( x*(b/d), n/d ) );
    }
}

int main() {
    int8 a, b, c, d;
    while( 1 ) {
        scanf( "%I64d%I64d%I64d%I64d", &a, &b, &c, &d );
        if( d==0 ) break;
        d = ((int8)1)<<d;
        a = b-a;
        if( a<0 ) a+=d;
        solver( c, a, d );
    }
}
