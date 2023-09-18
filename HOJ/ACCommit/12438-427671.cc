#include <cstdio>

int amount, del, ay[410];
int f[410][410];

int imin( int a, int b ) { return a<b?a:b; }
int imax( int a, int b ) { return a>b?a:b; }
void dp() {
    const int INF = 0x0fFfffff;
    f[0][0] = 0;
    for( int i=1; i<amount; ++i )
        f[0][i] = imax( f[0][i-1], ay[i]-ay[i-1] );
    for( int i=1; i<=del; ++i ) {
        f[i][i+1] = ay[i+1]-ay[0];
        for( int j=i+2; j<amount; ++j ) {
            f[i][j] = INF;
            for( int k=0; k<=i; ++k ) {
                int tmp, d;
                d = ay[j]-ay[j-k-1];
                if( d>f[i][j] ) break;
                tmp = imax( f[i-k][j-k-1], d );
                if( tmp<f[i][j] ) f[i][j] = tmp;
            }
        }
    }
    printf( "%d", f[del][amount-1] );
}

int main() {
    scanf( "%d%d", &amount, &del );
    ay[0] = 0;
    for( int i=0; i<amount; ++i )
        scanf( "%d", ay+i );
    dp();
}
