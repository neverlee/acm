#include <cstdio>
#include <cstring>
const int SIZE = 185000;
int map[SIZE][4], mlen;
int rect[610][610], size;
void init() {
    int i, j, k, d;
    char mtx[610][610];
    scanf( "%d", &size );
    for( int i=1; i<=size; ++i )
        scanf( "%s", mtx[i]+1 );
    memset( rect, 0, sizeof(rect) );
    for( i=0; i<=size+1; ++i )
        rect[0][i]=rect[size+1][i]=-1;
    for( i=1; i<=size; ++i )
        rect[i][0]=rect[i][size+1]=-1;
    for( int i=1; i<=size; ++i )
        for( int j=1; j<=size; ++j )
            if( mtx[i][j]!=\'#\' ) rect[i][j] = -1;
    for( i=1, d=1, k=0; i<=size; ++i, d=3-d ) {
        for( j=d; j<=size; j+=2 )
            if( rect[i][j]==0 )
                rect[i][j] = k++;
    }
    int dr[]={-1, 0, 0, 1};
    int dc[]={ 0,-1, 1, 0};
    for( i=1, d=2, mlen=0; i<=size; ++i, d=3-d ) {
        for( j=d; j<=size; j+=2, ++k )
            if( rect[i][j]!=-1 ) {
                for( k=0; k<4; ++k )
                    map[mlen][k]=rect[i+dr[k]][j+dc[k]];
                ++mlen;
            }
    }
}
int lby[SIZE];
bool yuse[SIZE];
bool getHalf( int to ) {
    int i, k;
    for( i=0; i<4; ++i ) {
        k = map[to][i];
        if( k>=0 && yuse[k]==0 ) {
            yuse[k]=1;
            if( lby[k]==-1 || getHalf( lby[k] ) ) {
                lby[k] = to;
                return 1;
            }
        }
    }
    return 0;
}
void getMax() {
    memset(lby, -1, sizeof(lby));
    int i, num;
    num = 0;
    for( i=0; i<mlen; ++i ) {
        memset(yuse, 0, sizeof(yuse));
        if( getHalf( i ) )
            ++num;
    }
    printf( "%d\n", num );
}
int main() {
    int T; scanf( "%d", &T );
    for( int t=1; t<=T; ++t ) {
        printf( "Case %d: ", t );
        init();
        getMax();
    }
}
