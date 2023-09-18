#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int x, y;
    Node (int ax, int ay) {
        x = ax;
        y = ay;
    }
};

vector<Node> dir;

const int SIZE = 1024;
class Maze {
    private:
        int row, col;
        char d[SIZE][SIZE];
    public:
        Maze() {
            scanf("%d%d", &row, &col);
            for (int i=1; i<=row; ++i) {
                scanf("%s", d[i]+1);
            }
            for (int i=0; i<=row+1; ++i) {
                d[i][0] = d[i][col+1] = 0;
            }
            for (int i=0; i<=col+1; ++i) {
                d[0][i] = d[row+1][i] = 0;
            }
        }
        char get(int x, int y) {
            return d[x][y];
        }
        int getRow() { return row; }
        int getCol() { return col; }
        Node getAddr(char c) {
            for (int i=1; i<=row; ++i) {
                for (int j=1; j<=col; ++j) {
                    if (d[i][j]==c) {
                        return Node(i, j);
                    }
                }
            }
            return Node(1,1);
        }
};


void initdir() {
    dir.push_back(Node(  1,  0 ));
    dir.push_back(Node( -1,  0 ));
    dir.push_back(Node(  0,  1 ));
    dir.push_back(Node(  0, -1 ));
}

int data[SIZE][SIZE];

void Find(Maze &m) {
    const int INF = 0x7FFFffff;
    for (int i=1; i<=m.getRow(); ++i) {
        for (int j=1; j<=m.getCol(); ++j) {
            data[i][j] = INF;
        }
    }

    queue<Node> qn;
    Node A = m.getAddr(\'A\');
    Node B = m.getAddr(\'B\');
    qn.push(A);
    data[A.x][A.y] = 0;

    while (!qn.empty()) {
        Node pre = qn.front();
        qn.pop();

        for (int i=0; i<dir.size(); ++i) {
            Node &d = dir[i];
            Node next(pre.x+d.x, pre.y+d.y);

            if ((m.get(next.x, next.y) == \'O\' || m.get(next.x, next.y) == \'B\')
                    && data[pre.x][pre.y] + 1 < data[next.x][next.y]) {
                data[next.x][next.y] = 1 + data[pre.x][pre.y];
                qn.push(next);
            }
        }
    }
    
    printf("%d", data[B.x][B.y]!=INF?data[B.x][B.y]:-1);
}



int main() {
    Maze m;
    initdir();
    Find(m);
}
