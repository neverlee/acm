#include<cstdio>
int main() {
    int t,n,k,l; scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d", &n );
        k = n-n/2;
        l = n/3;
        if( l%2==0 ) ++l;
        if( l*3+1<=n ) l+=2;
        printf( "%d\n", k+(n-l)/2+1 );
    }
}