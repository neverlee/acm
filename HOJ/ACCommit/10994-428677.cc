#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int mut[110][110], sz;
int cnt[110];

void init() {
    int x, y;
    memset( mut, 0, sizeof(mut) );
    memset( cnt, 0, sizeof(cnt) );
    for( int i=0; i<=sz+1; ++i )
        mut[0][i] = mut[i][0] = mut[sz+1][i] = mut[i][sz+1] = -1;
    for( int i=1; i<sz; ++i )
        for( int j=0; j<sz; ++j ) {
            scanf( "%d%d", &x, &y );
            mut[x][y] = i;
        }
}

void bfs( int sx, int sy ) {
    const int dx[] = { -1, 0, 1, 0 };
    const int dy[] = {  0,-1, 0, 1 };
    queue<int> qi;
    int nx, ny, rs;
    ++cnt[ mut[sx][sy] ];
    rs = mut[sx][sy];
    qi.push( sx | (sy<<8) );
    while( !qi.empty() ) {
        sx = qi.front()&0xff;
        sy = qi.front()>>8;
        qi.pop();
        mut[sx][sy] = -1;
        for( int i=0; i<4; ++i ) {
            nx = sx+dx[i];
            ny = sy+dy[i];
            if( mut[nx][ny] == rs )
                qi.push( nx | (ny<<8) );
        }
    }
}

bool work() {
    for( int i=1; i<=sz; ++i )
        for( int j=1; j<=sz; ++j )
            if( mut[i][j] != -1 )
                bfs( i, j );
    for( int i=0; i<sz; ++i )
        if( cnt[i]>1 ) return 0;
    return 1;
}

int main() {
    while( scanf( "%d", &sz ), sz ) {
        init();
        if( work() ) puts("good");
        else puts("wrong");
    }
}
