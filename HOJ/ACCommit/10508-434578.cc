#include <cstdio>

const int N=20;
int sum, amount, ay[N];
bool v[N], hv;

void output() {
    int i;
    for( i=1; !v[i] && i<=amount; ++i );
    printf( "%d", ay[i] );
    for( ++i; i<=amount; ++i )
        if( v[i] ) printf( "+%d", ay[i] );
    puts("");
}

void dg( int get, int lv ) {
    if( get>sum ) return;
    if( get==sum ) {
        hv = 1;
        output();
        return;
    }
    if( lv>amount ) return;
    if( ay[lv-1]!=ay[lv] || v[lv-1] ) {
        v[lv] = 1;
        dg( get+ay[lv], lv+1 );
    }
    v[lv] = 0;
    dg( get, lv+1 );
}

int main() {
    while( scanf( "%d%d", &sum, &amount ), sum ) {
        hv=0;
        for( int i=1; i<=amount; ++i ) scanf( "%d", ay+i );
        printf( "Sums of %d:\n", sum );
        dg( 0, 1 );
        if( !hv ) puts("NONE");
    }
}
