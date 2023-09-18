#include <cstdio>

int main() {
    int n, t;
    n = 0;
    for( int i=0; i<10; ++i ) {
        scanf( "%d", &t );
        n += !t;
    }
    t = 0;
    if( n>=2 ) t += n*(n-1)/2;
    if( n>=3 ) t += n*(n-1)*(n-2)/6;
    printf( "%d", 1-t%2 );
}
