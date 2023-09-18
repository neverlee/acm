#include <cstdio>

int main() {
    unsigned l, p, v, r;
    for (int i=1; scanf("%u%u%u", &l, &p, &v), l||p||v; ++i) {
        r = v/p*l + (v%p<l?v%p:l);
        printf("Case %d: %u\n", i, r);
    }
}
