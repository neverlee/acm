#include <cstdio>

const int N=41;
int f[N] = {0, 1, 2};
int main() {
    f[0] = 0;
    for (int i=3; i<N; ++i) {
        f[i] = f[i-2] + f[i-1];
    }
    int n;
    while (scanf("%d", &n), n) {
        printf("%ld\n", f[n]);
    }
}