#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point{
    int x, y;
    Point( int ax=-1, int ay=-1 ) {
        x=ax; y=ay;
    }
};

int xlen, ylen;
char str[200];
char info[60][60];
int dist[60][60];
int gmap[110][110];
int npoint;
Point alien[110];

void init() {
    gets( str );
    sscanf( str, "%d%d", &ylen, &xlen );
    for( int i=0; i<xlen; ++i )
        gets( info[i] );
    npoint = 0;
    for( int i=0; i<xlen; ++i )
        for( int j=0; j<ylen; ++j )
            if( info[i][j]==\'A\' || info[i][j]==\'S\' ) {
                alien[npoint].x = i;
                alien[npoint].y = j;
                ++npoint;
                info[i][j] = \'A\';
            }
}

void bfs( Point start ) {
    const int dx[] = { -1, 0, 1, 0 };
    const int dy[] = {  0,-1, 0, 1 };
    for( int i=0; i<xlen; ++i )
        for( int j=0; j<ylen; ++j )
            dist[i][j] = 0x0fFfFfFf;
    queue<Point> qp;
    dist[ start.x ][ start.y ] = 0;
    qp.push( start );
    while( !qp.empty() ) {
        int px, py, nx, ny;
        px = qp.front().x;
        py = qp.front().y;
        qp.pop();
        for( int i=0; i<4; ++i ) {
            nx = px + dx[i];
            ny = py + dy[i];
            if( info[nx][ny] == \'#\' ) continue;
            if( dist[nx][ny] > dist[px][py] + 1 ) {
                dist[nx][ny] = dist[px][py] + 1;
                qp.push( Point( nx, ny ) );
            }
        }
    }
}

void initgmap() {
    for( int i=0; i<npoint; ++i ) {
        bfs( alien[i] );
        for( int j=0; j<npoint; ++j )
            gmap[i][j] = dist[ alien[j].x ][ alien[j].y ];
    }
}

void prim() {
    int low[110], sum=0;
    for( int i=1; i<npoint; ++i )
        low[i] = gmap[0][i];
    low[0] = -1;
    for( int i=1; i<npoint; ++i ) {
        int min, minid;
        min = 0x7fFfFfFf;
        for( int j=1; j<npoint; ++j ) {
            if( low[j] < min && low[j]!=-1 ) {
                min = low[j];
                minid = j;
            }
        }
        sum += min;
        low[ minid ] = -1;
        for( int j=1; j<npoint; ++j ) {
            if( gmap[minid][j] < low[j] && j!=minid ) {
                low[j] = gmap[minid][j];
            }
        }
    }
    printf( "%d\n", sum );    
}

int main() {
    int T;
    gets( str );
    sscanf( str, "%d", &T );
    while( T-- ) {
        init();
        initgmap();
        prim();
    }
}
