#include <cstdio>

int amount, div, ay[1010];

void init() {
    scanf( "%d%d", &amount ,&div );
    ay[0] = 0;
    for( int i=1; i<=amount; ++i ) {
        scanf( "%d", ay+i );
        ay[i] += ay[i-1];
    }
}

int f[1010][1010];

void dp() {
    int t;
    for( int i=0; i<=amount; ++i ) f[0][i] = 0;
    for( int k=1; k<=div; ++k ) {
        f[k][k] = ay[k];
        for( int i=k+1; i<=amount; ++i ) {
            f[k][i] = -2000000000;
            for( int d=k-1; d<i; ++d ) {
                t = f[k-1][d] + ay[i]-ay[d];
                f[k][i] = f[k][i]>t?f[k][i]:t;
            }
            f[k][i] = f[k][i]>f[k][i-1]?f[k][i]:f[k][i-1];
        }
    }
    printf( "%d", f[div][amount] );
}

int main() {
    init();
    dp();
}
