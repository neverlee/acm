#include <cstdio>

int main() {
    int n;
    int y, m, d;
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d", &y, &m, &d);
        int t = 0;
        t += (y-1)*195 + (y-1)/3*5;
        t += (m-1)*20 - (y%3!=0)*((m-1)/2);
        t += d-1;
        printf("%d\n", 196470 - t);
    }
}
