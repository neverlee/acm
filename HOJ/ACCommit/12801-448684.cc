#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N=501;
int n, m;
bool d[N][N];
bool visit[N];
int tree;

bool bfs(int i) {
    queue<int> qi;
    qi.push(i);
    visit[i] = 1;
    bool ret = 1;
    while (!qi.empty()) {
        int f = qi.front();
        qi.pop();
        for (int i=1; i<=n; ++i) {
            if (d[f][i]) {
                d[f][i] = d[i][f] = 0;
                if (visit[i]) {
                    ret = 0;
                } else {
                    visit[i] = 1;
                    qi.push(i);
                }
            }
        }
    }
    return ret;
}

int main() {
    for (int t=1; scanf("%d%d", &n, &m), n||m; ++t) {
        memset(d, 0, sizeof(d));
        memset(visit, 0, sizeof(visit));
        tree = 0;
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            d[a][b] = d[b][a] = 1;
        }
        for (int i=1; i<=n; ++i) {
            tree += (!visit[i] && bfs(i));
        }
        printf("Case %d: ", t);
        if (tree == 0) {
            puts("No trees.");
        } else if (tree == 1) {
            puts("There is one tree.");
        } else {
            printf("A forest of %d trees.\n", tree);
        }
    }
}
