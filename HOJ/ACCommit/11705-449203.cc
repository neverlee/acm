#include <cstdio>

const int N = 1000010;
int set[N];

int find(int n) {
    if (set[n] == n) {
        return n;
    } else {
        set[n] = find(set[n]);
        return set[n];
    }
}

int main() {
    int kid;
    for (int i=0; i<N; ++i) {
        set[i] = i;
    }
    scanf("%d", &kid);
    while (kid--) {
        int t;
        scanf("%d", &t);
        int p = find(t);
        printf("%d ", p);
        set[p] = p+1;
    }
}