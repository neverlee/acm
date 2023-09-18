#include <cstdio>

const int N=101;
long long f[N];
int main() {
    f[0] = 0;
    for (int i=1; i<N; ++i) {
        f[i] = i*i + f[i-1];
    }
    int n;
    while (scanf("%d", &n), n) {
        printf("%I64d\n", f[n]);
    }
}