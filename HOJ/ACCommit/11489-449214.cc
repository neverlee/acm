#include <cstdio>

const int N = 100010;
int n, f[N];
int main() {
    n = 0;
    int a, b;
    while (2 == scanf("%d%d", &a, &b)) {
        f[a-1] = b;
        ++n;
    }
    int max = 0, p = 2;
    for (int i=2; i<n; ++i) {
        int k = f[i]+f[i-1]+f[i-2];
        if (k>max) {
            max = k;
            p = i;
        }
    }
    printf("%d %d %d", p-1, p, p+1);
}