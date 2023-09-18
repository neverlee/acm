#include <cstdio>

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        while (a%b>0) {
            c = a%b;
            a = b;
            b = c;
        }
        printf("%d\n", b);
    }
}