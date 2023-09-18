#include <cstdio>

int main() {
    int q;
    long long l, r;
    int p, n;
    char c;
    l = r = 0;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %c %d", &p, &c, &n);
        if (c==\'(\') { l += n; }
        else { r += n; }
        puts(l==r?"Yes":"No");
    }
}