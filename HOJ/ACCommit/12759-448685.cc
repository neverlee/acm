#include <cstdio>

int main() {
    int n;
    char s[10];
    while (scanf("%d", &n), n) {
        while (n>=10) {
            sprintf(s, "%d", n);
            printf("%d ", n);
            n = 1;
            for (int i=0; s[i]; ++i) {
                n *= (s[i]-\'0\');
            }
        }
        printf("%d\n", n);
    }
}
