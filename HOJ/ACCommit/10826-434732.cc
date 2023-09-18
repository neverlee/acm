#include <cstdio>
#include <cstring>

const int N = 210;

int amount, x[N], y[N], t[N], ret;
bool fd[N][N];

void work( int sa, int sb ) {
    int get, hv;
    get = 0; hv = 0;
    __int64 ty, tx;
    ty = y[sb]-y[sa]; tx = x[sb]-x[sa];
    for( int i=0; i<amount; ++i )
        if( ty*(x[i]-x[sa])==tx*(y[i]-y[sa]) ) {
            ++get;
            t[hv++] = i;
        }
    for( int i=0; i<hv; ++i )
        for( int j=i; j<hv; ++j )
            fd[t[i]][t[j]] = 1;
    if( get>ret ) ret=get;
}
int main() {
    scanf( "%d", &amount );
    for( int i=0; i<amount; ++i )
        scanf( "%d%d", x+i, y+i );
    memset( t, 0, sizeof(0) );
    ret = 2;
    for( int i=0; i<amount; ++i )
        for( int j=i+1; j<amount; ++j )
            if( !fd[i][j] && (x[i]!=x[j]||y[i]!=y[j]) )
                work( i, j );
    if( ret==0 ) ret=amount;
    printf( "%d", ret );
}
