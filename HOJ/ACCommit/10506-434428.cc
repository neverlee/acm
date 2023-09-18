#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 110;
struct Node{
    int x, y;
    Node( int ax=0, int ay=0 ) { x = ax; y = ay; }
};

int xl, yl;
char mut[N][N];
int dx[] = { -1,-1,-1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1,-1, 1,-1, 0, 1 };
void bfs( int sx, int sy ) {
    mut[sx][sy] = 0;
    queue<Node> qn;
    qn.push( Node(sx, sy) );
    while( !qn.empty() ) {
        int px, py, nx, ny;
        px = qn.front().x;
        py = qn.front().y;
        qn.pop();
        for( int i=0; i<8; ++i ) {
            nx = px+dx[i]; ny = py+dy[i];
            if( mut[nx][ny]==\'@\' ) {
                mut[nx][ny]=0;
                qn.push( Node(nx,ny) );
            }
        }
    }
}

int main() {
    while( scanf( "%d%d", &xl, &yl ), xl ) {
        memset( mut, 0, sizeof(mut) );
        for( int i=1; i<=xl; ++i )
            scanf( "%s", mut[i]+1 );
        int ret=0;
        for( int i=1; i<=xl; ++i )
            for( int j=1; j<=yl; ++j )
                if( mut[i][j]==\'@\' ) {
                    ++ret;
                    bfs( i, j );
                }
        printf( "%d\n", ret );
    }
}
