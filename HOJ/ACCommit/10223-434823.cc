#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1001;
int x[N], y[N], nk, np, ret;
double k[N];
int main() {
    while( ~scanf( "%d", &np ) ) {
        if( np==0 ) return 0;
        for( int i=0; i<np; ++i )
            scanf( "%d%d", x+i, y+i );
        ret = 0;
        for( int i=0; i<np-1; ++i ) {
            nk = 0;
            for( int j=i+1; j<np; ++j )
                k[nk++] = ((double)y[j]-y[i])/((double)x[j]-x[i]);
            sort( k, k+nk );
            int imx=1, hv=1;
            for( int j=1; j<nk; ++j ) {
                if( k[j]==k[j-1] ){
                    ++hv;
                }else {
                    imx = imx>hv?imx:hv;
                    hv = 1;
                }
                imx = imx>hv?imx:hv;
            }
            ret = ret>imx?ret:imx;
        }
        printf( "%d\n", ret+1 );
    }
}
