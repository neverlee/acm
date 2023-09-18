#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 310;

int mut[N][N], xl, yl, yrl;

void input() {
    int sz[N];
    yrl = 0;
    scanf( "%d%d", &yrl, &xl );
    for( int i=0; i<yrl; ++i ) {
        scanf( "%d", sz+i );
        yl += sz[i];
    }
    for( int i=0; i<xl; ++i ) {
        int k = 0, t;
        for( int j=0; j<yrl; ++j ) {
            scanf( "%d", &t );
            for( int n=0; n<sz[j]; ++n, ++k )
                mut[i][k] = t;
        }
    }
}

int lx[N], ly[N], lky[N];
bool sx[N], sy[N];

bool path( int u ) {
    sx[u] = 1;
    for( int v=0; v<yl; ++v ) {
        if( !sy[v] && lx[u]+ly[v]==mut[u][v] ) {
            sy[v] = 1;
            if( lky[v]==-1 || path(lky[v]) ) {
                lky[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

void bestmatch() {
    for( int i=0; i<xl; ++i ) {
        lx[i] = 0;
        ly[i] = 0;
        for( int j=0; j<yl; ++j )
            lx[i] = max( mut[i][j], lx[i] );
    }
    memset( lky, -1, sizeof(lky) );

    for( int u=0; u<xl; ++u ) {
        while( 1 ) {
            memset( sx, 0, sizeof(sx) );
            memset( sy, 0, sizeof(sy) );
            if( path(u) ) break;
            int dx = 0x7FFFffff;
            for( int i=0; i<xl; ++i ) {
                if( sx[i] ) {
                    for( int j=0; j<yl; ++j )
                        if( !sy[j] )
                            dx = min( lx[i]+ly[j]-mut[i][j], dx );
                }
            }
            for( int i=0; i<xl; ++i )
                if( sx[i] ) lx[i]-=dx;
            for( int i=0; i<yl; ++i )
                if( sy[i] ) ly[i]+=dx;
        }
    }
    int sum=0;
    for( int i=0; i<yl; ++i )
        if( lky[i]>=0 ) sum += mut[lky[i]][i];
    printf( "%d", sum );
}

int main() {
    input();
    bestmatch();
}
