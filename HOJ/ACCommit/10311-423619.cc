#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 1010;

int f[2][SIZE], *fa, *fb, nz;
int main() {
    int T; scanf( "%d", &T );
    for( int t=1; t<=T; ++t ) {
        fa=f[0]; fb=f[1];
        scanf( "%d", &nz );
        memset( f, 0, sizeof(f) );
        for( int k=0; k<nz; ++k ) {
            for( int i=1; i<=nz; ++i ) {
                scanf( "%d", fb+i );
                int tmp=0;
                for( int o=-1; o<2; ++o )
                    tmp = tmp>fa[o+i]?tmp:fa[o+i];
                fb[i] += tmp;
            }
            swap( fa, fb );
        }
        for( int i=1; i<=nz; ++i )
            fa[0] = fa[0]>fa[i]?fa[0]:fa[i];
        printf( "Case %d:\n%d\n", t, fa[0] );
    }
}