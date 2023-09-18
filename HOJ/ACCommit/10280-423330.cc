#include <cstdio>
#include <cstring>

int bset[1010];
int ncity, nroad;
int ret;
int find( int n ) {
    if( bset[n]==n ) return n;
    else return ( bset[n] = find( bset[n] ) );
}

int main() {
    while( scanf( "%d%d", &ncity, &nroad ), ncity ) {
        for( int i=0; i<=ncity; ++i ) bset[i] = i;
        int x, y;
        ret = ncity-1;
        while( nroad-- ) {
            scanf( "%d%d", &x, &y );
            if( (x=find(x)) != (y=find(y)) ) {
                --ret;
                bset[x]=y;
            }
        }
        printf( "%d\n", ret );
    }
}