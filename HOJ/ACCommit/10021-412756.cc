#include <cstdio>
#include <cstring>

int n, m, k;
bool mux[110][110];

int lky[110];
bool used[110];
int ret;

bool link( int pk ) {
    for( int i=0; i<m; ++i )
    if( used[i]==0 && mux[pk][i]==1 ) {
        used[i] = true;
        if( lky[i]==-1 || link( lky[i] ) ) {
            lky[i] = pk;
            return true;
        }
    }
    return false;
}

int main() {
    while( 3 == scanf( "%d%d%d", &n, &m, &k ) ) {
        int a, b, c;
        memset( mux, 0, sizeof(mux) );
        for( int i=0; i<k; ++i ) {
            scanf( "%d%d%d", &a, &b, &c );
            mux[b][c]=1;
        }
        for( int i=0; i<n; ++i ) mux[i][0] = 0;
        for( int i=0; i<m; ++i ) mux[0][i] = 0;
        ret = 0;
        memset( lky, -1, sizeof(lky) );
        for( int i=0; i<n; ++i ) {
            memset( used, 0, sizeof(used) );
            if( link(i) ) {
                ++ret;
            }
        }
        printf( "%d\n", ret );
    }
}
            
