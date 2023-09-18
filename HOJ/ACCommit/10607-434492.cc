#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define X(n) ((n)&0xFF)
#define Y(n) (((n)>>8)&0xff)
#define G(x,y) ((x)|((y)<<8))
const int INF = 0x0FFFffff;
const int N = 60;

int xl, yl, sx, sy, ex, ey;
int f[2][N][N];

void init() {
    scanf( "%d%d", &xl, &yl );
    scanf( "%d%d%d%d", &sx, &sy, &ex, &ey );
    for( int i=0; i<xl; ++i )
        for( int j=0; j<yl; ++j )
            f[0][i][j] = f[1][i][j] = INF;
    --ex;--ey;--sx;--sy;
}

int dx[] = { -2,-2,-1,-1, 2, 2, 1, 1, 0, 0,-2, 2};
int dy[] = { -1, 1,-2, 2,-1, 1,-2, 2,-2, 2, 0, 0};

void bfs() {
    f[0][sx][sy] = 0;
    queue<int> qi;
    qi.push( G(sx,sy) );
    int px, py, nx, ny, t;
    while( !qi.empty() ) {
        t = qi.front();
        px = X(t); py = Y(t);
        while( !qi.empty() && qi.front()==t ) qi.pop();
        for( int i=0; i<12; ++i ) {
            nx = px+dx[i]; ny = py+dy[i];
            if( nx<0 || nx>=xl || ny<0 || ny>=yl ) continue;
            if( i<8 ) {
                t = f[0][px][py]+1;
                if( f[1][nx][ny]>t ) {
                    f[1][nx][ny] = t;
                    qi.push(G(nx,ny));
                }
            }else {
                t = f[1][px][py]+1;
                if( f[0][nx][ny]>t ) {
                    f[0][nx][ny] = t;
                    qi.push(G(nx,ny));
                }
            }
        }
    }
    t = f[0][ex][ey];
    if( t>f[1][ex][ey] ) t=f[1][ex][ey];
    printf( "%d", t );
}

int main() {
    init();
    bfs();
}
