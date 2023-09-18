#include <cstdio>
#include <cstring>

int sa[10010], sb[10010], la, lb, aa[10010], ab[10010];
int tb[20010];

void getmax() {
    int ret = 0, k1, k2, ra=0, rb=0, ib;
    for( int ia=1; ia<=la; ++ia ) {
        ib = tb[ sa[ia]+10000 ];
        if( ib!=-1 ) {
            k1 = aa[ia]-aa[ra];
            k2 = ab[ib]-ab[rb];
            ret += (k1>k2?k1:k2);
            ra = ia;
            rb = ib;
        }
    }
    k1 = aa[la]-aa[ra];
    k2 = ab[lb]-ab[rb];
    ret += (k1>k2?k1:k2);
    printf( "%d\n", ret );
}

int main() {
    aa[0] = ab[0] = 0;
    while( scanf( "%d", &la ), la ) {
        memset( tb, -1, sizeof(tb) );
        for( int i=1; i<=la; ++i ) {
            scanf( "%d", sa+i );
            aa[i] = aa[i-1]+sa[i];
        }
        scanf( "%d", &lb );
        for( int i=1; i<=lb; ++i ) {
            scanf( "%d", sb+i );
            ab[i] = ab[i-1]+sb[i];
            tb[ sb[i]+10000 ] = i;
        }
        getmax();
    }
}