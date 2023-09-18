#include <cstdio>
#include <cstring>

int mx[110][110];
int size;

int dx[] = {  0, 1, 0, -1  };
int dy[] = { -1, 0, 1,  0 };

int main() {
    while (scanf("%d", &size), size) {
        memset(mx, 0, sizeof(mx));
        for (int i=0; i<=size+1; ++i) {
            mx[0][i] = -1;
            mx[i][0] = -1;
            mx[size+1][i] = -1;
            mx[i][size+1] = -1;
        }
        int d = 0;
        int value = 1;
        int x = 1, y = size+1;
        int end = size*size;
        while (value<=end) {
            int nx, ny;
            nx = x + dx[d];
            ny = y + dy[d];
            if (mx[nx][ny]==0) {
                mx[nx][ny] = value++;
                x = nx; y = ny;
            } else {
                d = (d+1)%4;
            }
        }
        for (int i=1; i<=size; ++i) {
            printf("%d", mx[i][1]);
            for (int j=2; j<=size; ++j) {
                printf(" %d", mx[i][j]);
            }
            puts("");
        }
    }
}
