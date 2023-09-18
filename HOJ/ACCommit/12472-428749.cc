#include <cstdio>
#include <algorithm>

int a[3];
int ay[300], amount;
int getid( int ad[3] ) {
    int r=0;
    r = ad[0] | (ad[1]<<4) | (ad[2]<<8);
    return r;
}
void fromid( int ad[3], int id ) {
    ad[0] = id&0xf;
    ad[1] = (id&0xff)>>4;
    ad[2] = (id&0xfff)>>8;
}

void init() {
    for( int i=1; i<14; ++i )
        for( int j=1; j<14; ++j )
        if( i!=j ) {
            a[0] = a[1] = i;
            a[2] = j;
            std::sort( a, a+3 );
            ay[amount++] = getid( a );
        }
    for( int i=1; i<14; ++i ) {
        a[0] = a[1] = a[2] = i;
        ay[amount++] = getid(a);
    }
}
int main() {
    init();
    while( scanf( "%d%d%d", a+0, a+1, a+2 ), a[0] ) {
        std::sort( a, a+3 );
        int i, k=getid( a );
        for( i=0; i<amount; ++i )
            if( k==ay[i] ) break;
        if( i==amount-1 ) puts("*");
        else if( i==amount ) {
            puts( "1 1 2" );
        }else {
            fromid( a, ay[i+1] );
            printf( "%d %d %d\n", a[0], a[1], a[2] );
        }
    }
}
