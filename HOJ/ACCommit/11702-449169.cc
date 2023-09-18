#include <cstdio>

const int src = 10000;
int s[1010];
int f[2][1010];
int main() {
    int stop, time, step;
    while (3 == scanf("%d%d%d", &stop, &time, &step)) {
        for (int i=0; i<stop; ++i) {
            scanf("%d", s+i);
        }
        f[0][0] = src-s[0];
        for (int i=1; i<stop; ++i) {
            int t = f[0][i-1] - s[i];
            f[0][i] = t>0?t:0;
        }
        int p = 1;
        for (int k=1; k<=time; ++k) {
            f[p][0] = src;
            for (int i=1; i<stop; ++i) {
                f[p][i] = f[p][i-1] - s[i];
                for (int j=1; j<=step&&i-j>=0; ++j) {
                    int t = f[1-p][i-j] - s[i];
                    f[p][i] = f[p][i]>t?f[p][i]:t;
                }
            }
            p = 1-p;
        }
        if (f[1-p][stop-1]>0) {
            printf("%d\n", f[1-p][stop-1]);
        } else {
            puts("It is just a legend!");
        }
    }
}