#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ay[5001];

void init() {
    ay[0] = 0;
    char s[20];
    for (int i=1; i<=5000; ++i) {
        int good = 1;
        sprintf(s, "%d", i);
        int len = strlen(s);
        sort(s, s+len);
        for (int j=1; s[j]; ++j) {
            if (s[j-1]==s[j]) {
                good = 0;
            }
        }
        ay[i] = ay[i-1] + good;
    }
}
int main() {
    int n, m;
    init();
    while(~scanf("%d%d", &n, &m)) {
        printf("%d\n", ay[m]-ay[n-1]);
    }
}