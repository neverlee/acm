#include <cstdio>
#include <cstring>
int h, w, num;
char map[101][101];
int lky[101], yused[101];
bool toset( int to ) {
    int i;
    for( i=0; i<w; ++i )
    if( yused[i]==0 && map[to][i]==\'1\' ) {
        yused[i] = 1;
        if( lky[i]==-1 || toset( lky[i] ) ) {
            lky[i] = to;
            return 1;
        }
    }
    return 0;
}
int main() {
    while( 2 == scanf( "%d%d", &h, &w ) ) {
        int i;
        for( i=0; i<h; ++i ) scanf( "%s", map[i] );
        memset( lky, -1, sizeof(lky) );
        num = 0;
        for( i=0; i<h; ++i ) {
            memset( yused, 0, sizeof(yused) );
            if( toset( i ) )
                ++num;
        }
        printf( "%d\n", num );
    }
    return 0;
}