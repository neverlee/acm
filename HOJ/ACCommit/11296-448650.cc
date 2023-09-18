#include <cstdio>

int f(long long n) {
    n = 2*n+2;
    int low, mid, high;
    long long t;
    low = 0;
    high = 100000000;
    while (low<high) {
        mid = (low+high)>>1;
        t = (long long)mid*(mid+1);
        if (t >= n) {
            high = mid;
        } else {
            low = mid+1;
        }
    
    }
    return low;
}

int main() {
    long long n, low, mid, high;
    for (int t=1; scanf("%I64d", &n), n; ++t) {
        printf("Case %d: %d\n", t, f(n)+2);
    }
}