#include <cstdio>

int exgcd( int a, int b, int &x, int &y ) {
    if( b==0 ) { x=1; y=0; return a; }
    int d, t;
    d = exgcd( b, a%b, x, y );
    t=x; x=y; y=t-(a/b)*y;
    return d;
}
int m[] = {23,28,33}, b[4];
const int mi = 21252;
int china_reminder() {
    int x, y, ret=0, tm;
    for( int i=0; i<3; ++i ) {
        tm = mi/m[i];
        exgcd( tm, m[i], x, y );
        ret = ( ret + (__int64)tm*x*b[i] ) % mi;
    }
    return ret;
}

int main() {
    for( int T=1; ; ++T ) {
        for( int i=0; i<4; ++i )
            scanf( "%d", b+i );
        if( b[0]==-1 ) break;
        for( int i=0; i<3; ++i ) b[i] %= m[i];
        int ret = china_reminder();
        ret = ret-b[3];
        while( ret<=0 ) ret+=mi;
        printf( "Case %d: the next triple peak occurs in %d days.\n", T, ret );
    }
}