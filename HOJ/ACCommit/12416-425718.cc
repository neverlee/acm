#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int dv, amount, ay[1010];
int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d%d", &dv, &amount );
        ++dv;
        for( int i=0; i<amount; ++i )
            scanf( "%d", ay+i );
        sort( ay, ay+amount, greater<int>() );
        int ret, can;
        can = amount/dv;
        ret = 0;
        for( int i=0; i<can; ++i )
            ret += ay[i];
        printf( "%d\n", ret );
    }
}