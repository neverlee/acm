#include <cstdio>
#include <cstring>

const int N=210;
char mt[N][N];
int hv[N];
int xl, yl;

void work() {
    for( int i=0; mt[1][i]; ++i ) {
        for( int j=1; j<=yl; )
        if( mt[j][i]==\'0\' ) {
            int cnt=0;
            while( mt[j++][i]==\'0\' )
                ++cnt;
            ++hv[cnt];
        }else ++j;
    }
    for( int i=1; i<=xl; ++i )
        if( hv[i] ) printf( "%d %d\n", i, hv[i] );
}

int main() {
    scanf( "%d%d", &xl, &yl );
    for( int i=1; i<=xl; ++i )
        scanf( "%s", mt[i] );
    memset( mt[0], \'1\', sizeof(mt[0]) );
    memset( mt[xl+1], \'1\', sizeof(mt[xl+1]) );
    memset( hv, 0, sizeof(hv) );
    work();
}
