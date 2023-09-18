#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

const int N = 5001;
const int msize = 5000;

int v, e;
int maps[N][N], mapr[N][N];
int set[N];
bool visited[N];
stack<int> si;

void dfsmaps(int p) {
    visited[p] = true;
    for (int i=0; i<maps[p][msize]; ++i) {
        if (!visited[maps[p][i]]) {
            dfsmaps(maps[p][i]);
        }
    }
    si.push(p);
}

void dfsmapr(int p) {
    visited[p] = true;
    for (int i=0; i<mapr[p][msize]; ++i) {
        if (!visited[mapr[p][i]]) {
            dfsmapr(mapr[p][i]);
        }
    }
    set[p] = si.top();
}

int main() {
    while (scanf("%d%d", &v, &e) == 2 && v!=0) {
        for (int i=0; i<v; ++i) {
            maps[i][msize] = 0;
            mapr[i][msize] = 0;
            set[i] = i;
        }
        
        for (int i=0; i<e; ++i) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            --v1; --v2;
            maps[v1][maps[v1][msize]++] = v2;
            mapr[v2][mapr[v2][msize]++] = v1;
        }


        memset(visited, 0, sizeof(visited));
        for (int i=0; i<v; ++i) {
            if (!visited[i]) {
                dfsmaps(i);
            }
        }
        memset(visited, 0, sizeof(visited));
        while (!si.empty()) {
            int t = si.top();
            if (!visited[t]) {
                dfsmapr(t);
            }
            si.pop();
        }
        
        memset(visited, 1, sizeof(visited));
        for (int i=0; i<v; ++i) {
            for (int j=0; j<maps[i][msize]; ++j) {
                if (set[i] != set[maps[i][j]]) {
                    visited[set[i]] = 0;
                }
            }
        }
        for (int i=0; i<v; ++i) {
            if (visited[set[i]]) {
                printf("%d ", i+1);
            }
        }
        puts("");
    }
}