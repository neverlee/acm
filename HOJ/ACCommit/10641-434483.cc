#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 110;

int mut[N][N], sz;
    char buf[1000];

void input() {
    int x, y;
    memset( mut, 0, sizeof(mut) );
    for( int i=1; i<sz; ++i ) {
        for( int j=0; j<sz; ++j ) {
            scanf( "%d%d", &x, &y );
            mut[x][y] = i;
        }
        gets(buf);
    }
    for( int i=0; i<=sz+1; ++i )
        mut[0][i] = mut[i][0] = mut[i][sz+1] = mut[sz+1][i] = -1;
}

int dx[] = { -1, 0, 0, 1 };
int dy[] = {  0,-1, 1, 0 };

int bfs( int sx, int sy ) {
    queue<int> qx, qy;
    int cnt, rct, px, py, nx, ny;
    rct = mut[sx][sy];
    mut[sx][sy] = -1;
    qx.push(sx); qy.push(sy);
    cnt = 1;
    while( !qx.empty() ) {
        px = qx.front(); py = qy.front();
        qx.pop(); qy.pop();
        for( int i=0; i<4; ++i ) {
            nx = px+dx[i];
            ny = py+dy[i];
            if( mut[nx][ny] == rct ) {
                ++cnt;
                mut[nx][ny] = -1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
    return cnt;
}

bool work() {
    for( int i=1; i<=sz; ++i )
        for( int j=1; j<=sz; ++j )
        if( mut[i][j]>=0 )
            if( bfs(i,j)!=sz ) return 0;
    return 1;
}

int main() {
    while( ~scanf( "%d", &sz )&&sz ) {
        input();
        if( work() ) puts("good");
        else puts("wrong");
    }
}
