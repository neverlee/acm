#include <cstdio>
#include <cstring>

char mx[60][60];
int size, ret;
int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};
void dfs(int x, int y) {
    for (int i=0; i<4; ++i) {
        int nx, ny;
        nx = x+dx[i];
        ny = y+dy[i];
        if (mx[nx][ny]==\'.\') {
            mx[nx][ny] = 0;
            dfs(nx, ny);
        }
    }
}

int main() {
    while (~scanf("%d", &size)) {
        memset(mx, 0, sizeof(mx));
        for (int i=1; i<=size; ++i) {
            scanf("%s", mx[i]+1);
        }
        ret = 0;
        for (int i=1; i<=size; ++i) {
            for (int j=1; j<=size; ++j) {
                if (mx[i][j] == \'.\') {
                    ++ret;
                    mx[i][j] = 0;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ret);
    }
}