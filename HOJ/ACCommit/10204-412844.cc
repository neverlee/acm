#include <cstdio>

int main() {
    int n;
    puts( " Cards  Overhang" );
    while( EOF != scanf( "%d", &n ) ) {
        double d=1, sum=0;
        for( int i=1; i<=n; ++i ) {
            sum += d/(i<<1);
        }
        printf( "%5d   %7.3lf\n", n, sum );
    }
}
