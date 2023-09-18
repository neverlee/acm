#include <cstdio>

int main() {
    int n;
    for( int T=1; scanf( "%d", &n ), n; ++T ) {
        printf( "Set %d: ", T );
        int x1, x2, y1, y2, a1, a2, b1, b2;
        scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );
        for( int i=1; i<n; ++i ) {
            scanf( "%d%d%d%d", &a1, &b1, &a2, &b2 );
            x1 = x1>a1?x1:a1;
            x2 = x2<a2?x2:a2;
            y1 = y1>b1?y1:b1;
            y2 = y2<b2?y2:b2;
        }
        if( x1>=x2 || y1>=y2 ) puts("No overlap");
        else printf( "(%d,%d), (%d,%d)\n", x1, y1, x2, y2 );
    }
}
