#include <cstdio>

int main() {
    int n;
    char s[20];
    while (scanf("%d", &n), n) {
        while (n>=10) {
            printf("%d ", n);
            sprintf(s, "%d", n);
            n = 1;
            for (int i=0; s[i]; ++i) {
                n *= s[i]-\'0\';
            }
        }
        printf("%d\n", n);
    }
}