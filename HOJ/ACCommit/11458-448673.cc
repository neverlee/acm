#include <cstdio>
#include <cstring>

const int SIZE = 110;
const int INF = 0x0fffFFFF;
int dx[SIZE][SIZE];
int city, road;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &city, &road);
        for (int i=0; i<city; ++i) {
            for (int j=0; j<city; ++j) {
                dx[i][j] = INF;
            }
        }
        
        while (road--) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            dx[u][v] = dx[u][v]<w?dx[u][v]:w;
        }

        for (int k=0; k<city; ++k) {
            for (int i=0; i<city; ++i) {
                for (int j=0; j<city; ++j) {
                    int t = dx[i][k] + dx[k][j];
                    dx[i][j] = dx[i][j]<t?dx[i][j]:t;
                }
            }
        }
        int ret = INF;
        for (int i=0; i<city; ++i) {
            ret = ret<dx[i][i]?ret:dx[i][i];
        }
        if (ret==INF) {
            ret = -1;
        }
        printf("%d\n", ret);

    }
}