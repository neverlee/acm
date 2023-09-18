#include <cstdio>

int main() {
    int amount, t;
    int sum, max, min, rmax, rmin;
    while (~scanf("%d", &amount)) {
        sum = 0;
        max = -1;
        min = 0;
        rmax = 0;
        rmin = 0;

        for (int i=0; i<amount; ++i) {
            scanf("%d", &t);
            
            sum += t;
            rmax = rmax>0 ? rmax+t : t;
            max = max>rmax?max:rmax;
            rmin = rmin<0 ? rmin+t : t;
            min = min<rmin?min:rmin;
        }
        int ret = max>sum-min?max:sum-min;
        printf("%d\n", ret);
    }
}