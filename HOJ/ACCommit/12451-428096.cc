#include <cstdio>
#include <algorithm>

int main() {
    int T, n, mx, mi, gp, ay[60];
    scanf( "%d", &T );
    for( int t=1; t<=T; ++t ) {
        scanf( "%d", &n );
        for( int i=0; i<n; ++i )
            scanf( "%d", ay+i );
        std::sort( ay, ay+n );
        gp = 0;
        for( int i=1; i<n; ++i ) {
            int xx = ay[i]-ay[i-1];
            if( xx>gp ) gp = xx;
        }
        mx = ay[n-1]; mi = ay[0];
        printf( "Class %d\n", t );
        printf( "Max %d, Min %d, Largest gap %d\n", mx, mi, gp );
    }
}
