#include <cstdio>
#include <cstring>

const int N = 400;
int vl, gl;
int f[N][N];

int main() {
    int amount;
    scanf( "%d%d%d", &vl, &gl, &amount );
    memset( f, -1, sizeof(f) );
    f[0][0] = 0;
    int ti, vi, gi, tmp, nx, ny;
    while( amount-- ) {
        scanf( "%d%d%d", &ti, &vi, &gi );
        for( int i=vl-vi; i>=0; --i ) {
            for( int j=gl-gi; j>=0; --j )
            if( -1 != f[i][j] ) {
                tmp = f[i][j]+ti;
                nx = i+vi; ny=j+gi;
                if( f[nx][ny]==-1 || tmp>f[nx][ny] )
                    f[nx][ny] = tmp;
            }
        }
    }
    tmp = 0;
    for( int i=1; i<=vl; ++i )
        for( int j=1; j<=gl; ++j )
            tmp = tmp>f[i][j]?tmp:f[i][j];
    printf( "%d", tmp );
}
