#include <stdio.h>

int main() {
    int k, n;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        puts(n>2?"E":"G");
    }
    return 0;
}