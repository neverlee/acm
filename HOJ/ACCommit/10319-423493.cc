#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, ay[1010];
int f[1010][1010];
int p[1010][1010];
const int INF = 0x7fFfFfff;
void init() {
    scanf( "%d", &n );
    ay[0] = 0;
    for( int i=1; i<=n; ++i )
        scanf( "%d", ay+i );
    sort( ay+1, ay+1+n );
    for( int i=1; i<=n; ++i ) {
        f[i][i] = ay[i];
        ay[i] += ay[i-1];
        p[i][i] = i;
    }
}

int sum( int i, int j ) {
    return ay[i]-ay[j-1];
}

void dp() {
    for( int l=1; l<n; ++l ) {
        for( int i=1, j=i+l; j<=n; ++i, ++j ) {
            int ps, pe;
            ps = p[i][j-1];
            pe = p[i+1][j];
            f[i][j] = INF;
            for( int k=ps; k<=pe; ++k ) {
                int m;
                m = f[i][k-1]+f[k+1][j]+sum(j,i);
                if( m<f[i][j] ) {
                    f[i][j] = m;
                    p[i][j] = k;
                }
            }
        }
    }
    printf( "%d", f[1][n] );
}


int main() {
    init();
    dp();
}