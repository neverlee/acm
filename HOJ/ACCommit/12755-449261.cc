#include <cstdio>

int main() {
    bool yn[181] = {0};
    for (int i=0; i<720; ++i) {
        int h, m, a;
        h = i/12*6;
        m = i%60*6;
        a = h>m?h-m:m-h;
        a = a>180?360-a:a;
        yn[a] = 1;
    }
    int n;
    while (~scanf("%d", &n)) {
        puts(yn[n]?"Y":"N");
    }
}