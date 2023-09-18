#include <cstdio>
int rk[30], rt[30];
int main() {
    for( int i=0, k=2; i<30; ++i, k<<=1 )
        rk[i] = k-1;
    int n;
    while( scanf( "%d", &n ), n!=-1 ) {
        int p;
        for( p=0; n>=rk[p]; ++p );
        int in=n, l=0;
        for( int i=p-1; in&&i>=0; --i ) {
            if( in==rk[i]*2 ) {
                rt[l++] = i;
                rt[l++] = i;
                in = 0;
            }else if( in>=rk[i] ) {
                in -= rk[i];
                rt[l++] = i;
            }
        }
        printf( "%d [", n );
        for( int i=l-1; i>0; --i )
            printf( "%d,", rt[i] );
        if( n>0 ) printf( "%d", rt[0] );
        puts( "]" );
    }
}