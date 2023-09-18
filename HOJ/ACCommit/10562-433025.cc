#include <cstdio>
#include <cmath>

int n, ay[60];

int gcd( int a, int b ) {
    int t;
    while( b ) {
        t=a;
        a = b;
        b = t%b;
    }
    return a;
}

int main() {
    while( scanf( "%d", &n ), n ) {
        for( int i=0; i<n; ++i )
            scanf( "%d", ay+i );
        int b, s;
        b = 3*n*(n-1);
        s = 0;
        for( int i=0; i<n; ++i )
            for( int j=i+1; j<n; ++j )
                s += gcd( ay[i], ay[j] )==1;
        if( s==0 ) puts( "No estimate for this data set." );
        else printf( "%.6lf\n", sqrt(b/(double)s) );
    }
}
