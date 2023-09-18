#include <cstdio>
#include <cmath>
double x, y, c;
int main() {
    while( EOF != scanf( "%lf%lf%lf", &x, &y, &c ) ) {
        double lx, ly, high, mid, low, mm, xx, yy, lh;
        xx = x*x;
        yy = y*y;
        low = 0;
        high = x<y?x:y;
        for( int i=0; i<100; ++i ) {
            mid = (low+high)/2.0;
            mm = mid*mid;
            lx = sqrt( xx-mm );
            ly = sqrt( yy-mm );
            lh = lx*ly/(lx+ly);
            if( lh>c ) low = mid;
            else high = mid;
        }
        printf( "%.3lf\n", mid );
    }
}
        