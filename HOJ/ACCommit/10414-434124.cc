#include <cstdio>

const int N = 256;

int sz, lz;
int f[N][N];

int X( int n ) {
    if( n<0 ) return 0;
    if( n>sz ) return sz;
    return n;
}

int main() {
    scanf( "%d%d", &sz, &lz );
    for( int i=1; i<=sz; ++i )
        for( int j=1; j<=sz; ++j ) {
            scanf( "%d", f[i]+j );
            f[i][j] += ( f[i-1][j]+f[i][j-1]-f[i-1][j-1] );
        }
    int a,b,c,d, g;
    for( int i=1; i<=sz; ++i ) {
        for( int j=1; j<=sz; ++j ) {
            a = X(i+lz); b = X(j+lz);
            c = X(i-lz-1); d = X(j-lz-1);
            g = f[a][b]+f[c][d]-f[a][d]-f[c][b];
            if( j!=1 ) putchar(\' \');
            printf( "%d", g );
        }
        putchar(\'\n\');
    }
}
