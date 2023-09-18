#include <cstdio>
#include <cmath>

const double PI = acos(-1);
const double esp = 1E-7;
int a, b, v, A, s;

int main() {
    while( scanf( "%d%d%d%d%d", &a, &b, &v, &A, &s ), a ) {
        double vh, vv, dh, dv;
        vh = v * cos( PI*A/180.0 );
        vv = v * sin( PI*A/180.0 );
        dh = vh*s/2.0 - a/2.0;
        dv = vv*s/2.0 - b/2.0;
        int sh, sv;
        if( dh+esp<0.0 ) sh=0;
        else sh = (dh+esp)/a + 1;
        if( dv+esp<0.0 ) sv=0;
        else sv = (dv+esp)/b + 1;
        printf( "%d %d\n", sh, sv );
    }
}

