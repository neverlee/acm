#include <cstdio>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%I64d\n", (((long long)1)<<n)-1);
    }
}