#include <cstdio>
#include <cstring>

const int BUY = 110;
const int STORE = 100010;

int buy, store;
int b[BUY], s[STORE], v[STORE];
int f[BUY][STORE];


int main() {
    while (scanf("%d%d", &buy, &store), buy||store) {
        for (int i=1; i<=buy; ++i) {
            scanf("%d", b+i);
        }
        for (int i=1; i<=store; ++i) {
            scanf("%d%d", s+i, v+i);
        }

        memset(f[0], 0, sizeof(f[0]));
        
        for (int i=1; i<=buy; ++i) {
            f[i][0] = -1;
            for (int j=1; j<=store; ++j) {
                f[i][j] = f[i][j-1];
                if (b[i] == s[j] && f[i-1][j-1] != -1) {
                    int t = f[i-1][j-1] + v[j];
                    if (f[i][j]==-1 || f[i][j]>t) {
                        f[i][j] = t;
                    }
                }
                //printf("%4d", f[i][j]);
            }
            //puts("");
        }
        if (f[buy][store] == -1) {
            puts("Impossible");
        } else {
            printf("%d\n", f[buy][store]);
        }
    }
}