#include <cstdio>
#include <queue>
using namespace std;

int xl, yl, sx, sy, ex, ey;
int mat[110][110], f[110][110];

const int dx[] = { -1, 0, 1, 0};
const int dy[] = {  0,-1, 0, 1};
void bfs() {
    for( int i=0; i<xl; ++i )
        for( int j=0; j<yl; ++j )
            f[i][j] = 0x0FFFffff;
    queue<int> qx, qy;
    qx.push(sx); qy.push(sy);
    f[sx][sy] = 1;
    int px, py, cx, cy;
    while( !qx.empty() ) {
        px = qx.front(); py = qy.front();
        qx.pop(); qy.pop();
        if( px==ex && py==ey ) break;
        for( int i=0; i<4; ++i ) {
            cx = px+dx[i]; cy = py+dy[i];
            if( cx<0||cx>=xl || cy<0||cy>=yl || mat[cx][cy] ) continue;
            if( f[cx][cy] > f[px][py]+1 ) {
                f[cx][cy] = f[px][py]+1;
                qx.push(cx); qy.push(cy);
            }
        }
    }
    printf( "%d\n", f[ex][ey] );
}

int main() {
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d%d", &yl, &xl );
        for( int i=0; i<xl; ++i )
            for( int j=0; j<yl; ++j )
                scanf( "%d", mat[i]+j );
        scanf( "%d%d%d%d", &sy, &sx, &ey, &ex );
        bfs();
    }
}
