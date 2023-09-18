#include <cstdio>
#include <cstring>

int ncity, nday;
int in[110][110], out[110][110];

void init() {
    for( int i=0; i<ncity; ++i )
        for( int j=0; j<ncity; ++j )
            scanf( "%d", out[i]+j );
    for( int i=1; i<=nday; ++i )
        for( int j=0; j<ncity; ++j )
            scanf( "%d", in[i]+j );
}

const int INF = 0x0fffFfff;
int f[110][110];
void imax( int &a, int b ) { a = a>b?a:b; }
void dp() {
    for( int i=0; i<ncity; ++i )
        f[nday][i] = 0;
    for( int k=nday-1; k>=0; --k ) {
        for( int i=0; i<ncity; ++i ) {
            f[k][i] = -INF;
            for( int j=0; j<ncity; ++j ) {
                imax( f[k][i], f[k+1][j]+in[k+1][j]-out[i][j] );
            }
        }
    }
    printf( "%d\n", f[0][0] );
}

int main() {
    while( scanf( "%d%d", &ncity, &nday ), ncity ) {
        init();
        dp();
    }
}
