#include <cstdio>

int main() {
    int l, n;
    while (scanf("%d%d", &l, &n), l||n) {
        int p, m=0;
        char d;
        while (n--) {
            scanf("%d %c", &p, &d);
            if (d==\'R\') {
                m = m>l-p?m:l-p;
            } else {
                m = m>p?m:p;
            }
        }
        printf("The last ant will fall down in %d seconds.\n", m);
    }
}