#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1008008
int map[1008][1008], q[100008];
int fat[N];
int n, m, ans;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
inline int ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y<m;
}
struct point {
    int x, y;
    point(int xx = 0, int yy = 0) : x(xx), y(yy) { }
    bool operator<(const point & r) const { return map[r.x][r.y] < map[x][y]; }
} p[N];
inline int find(int x) {
    return (x == fat[x]) ? x : (fat[x] = find(fat[x]));
}
inline void union_set(const int a, const int b) {
    int k = a*m+b;
    for (int i = 0; i < 4; i++) {
        int x = a + dx[i], y = b + dy[i];
        if (ok(x, y) && map[x][y] < 0) {
            int f1 = find(k), f2 = find(x*m+y);
            if (f1 != f2) { fat[f1] = f2;  --ans;}
        }
    }
}
int main() {
    int i, j, t, x, y, Q;
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j) {
                scanf("%d", map[i] + j);
                fat[i*m+j] = i*m+j;
                p[i*m+j] = point(i, j);
            }
        sort(p, p + n*m);
        scanf("%d", &Q);
        for (i = 0; i < Q; ++i) scanf("%d", q + i);
        for (ans = t = 0, i = Q - 1; i >= 0; --i) {
            while (1) {
                x = p[t].x, y = p[t].y;
                if (map[x][y] > q[i]) {
                    ++ans;
                    union_set(x,y);
                    map[x][y] = -1;
                    ++t;
                } else break;
            }
            q[i] = ans;
        }
        for (i = 0; i < Q; ++i) printf("%d ", q[i]);
        printf("\n");
    }
    return 0;
}
