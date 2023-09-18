#include <cstdio>
#include <cstring>

int n, k, d;

void binary( int on, int k ) {
    for( int i=k-1; i>=0; --i )
        printf( "%d", (on>>i)&1 );
}

int main() {
    scanf( "%d", &n );
    for( k=0; (1<<k)<n; ++k );
    --k;
    d = (1<<(k+1))-n;
    for( int i=0; i<d; ++i ) {
        binary( i, k );
        putchar(\'\n\');
    }
    int e = (d+n)/2;
    for( int i=d; i<e; ++i ) {
        binary( i, k );
        puts("0");
        binary( i, k );
        puts("1");
    }
}
