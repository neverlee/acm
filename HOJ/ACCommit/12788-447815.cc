#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int a[30], l;
    char s[100];
    while (~scanf("%d%d", &a[0], &l)) {
        if (!a[0]&&!l) {
            break;
        }

        char p[20];
        sprintf(p, "%%0%dd %%0%dd", l, l);
        bool flag=1;
        for (int i=1; flag; ++i) {
            sprintf(s, p, a[i-1], a[i-1]);
            sort(s, s+l, greater<int>());
            sort(s+l+1, s+l+1+l);
            int p, q;
            sscanf(s, "%d %d", &p, &q);
            a[i] = p-q;
            for (int j=0; j<i; ++j) {
                if (a[j]==a[i]) {
                    printf("%d %d %d\n", j, a[i], i-j);
                    flag=0;
                }
            }
        }
    }
}
