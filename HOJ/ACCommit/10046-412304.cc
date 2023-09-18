#include <cstdio>
#include <cmath>

int main() {
        int D, H, B, L, N;
        scanf ("%d", &N);
        for (int I=1; I<=N; ++I) {
                scanf ("%d%d%d%d", &D, &H, &B, &L);
                double b, l, n;
                n = B/D+(B%D?1:0);
                b = B/n; l = L/n;
                double low, high, mid;
                low = 0; high = H;
                for (int i=0; i<100; ++i) {
                        mid = (low+high)/2.0;
                        double lxy, x, y, lt;
                        x = b/2.0;
                        y = H-mid;
                        lt = sqrt(x*x+4*y*y);
                        lxy = lt+x*x/(2.0*y)*log((2*y+lt)/x);
                        lxy *= n;
                        if( lxy>L ) low = mid;
                        else high = mid;
                }
                printf ("Case %d:\n", I);
                printf ("%.2lf\n", low);
                if (I!=N) puts("");
        }
}
