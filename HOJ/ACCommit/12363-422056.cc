#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int SIZE = 1010;
const int MOD = 0x7fFfFfFf;
const int dx[] = { 1, 0, -1, 0  };
const int dy[] = { 0, 1,  0, -1 };

int nsz;
char info[SIZE][SIZE];
unsigned int dist[SIZE][SIZE];

int ways() {
    memset( dist, 0, sizeof(dist) );
    dist[1][1] = 1;
    for( int i=2; i<nsz+nsz; ++i ) {
        int x, y;
        x = i<nsz?i:nsz;
        y = i-x+1;
        for( ; x>0 && y<=nsz; --x,++y )
        if( info[x][y]==\'.\' )
            dist[x][y] = (dist[x-1][y]+dist[x][y-1])%MOD;
    }
    return dist[nsz][nsz];
}
#define XX(x) ((x)&0xffff)
#define YY(y) ((y)>>16)
#define MAKE(x,y) ( ((x)&0xffff) | ((y)<<16) )
int arrive() {
    queue<int> qi;
    memset( dist, 0, sizeof(dist) );
    dist[1][1] = 1;
    qi.push( 0x00010001 );
    while( !qi.empty() ) {
        int px, py, nx, ny;
        px = XX( qi.front() );
        py = YY( qi.front() );
        for( int i=0; i<4; ++i ) {
            nx = px+dx[i];
            ny = py+dy[i];
            if( info[nx][ny]==\'.\' && dist[nx][ny]==0 ) {
                dist[nx][ny]=1;
                qi.push( MAKE( nx, ny ) );
            }
        }
        qi.pop();
    }
    return dist[nsz][nsz];
}

int main() {
    while( EOF != scanf( "%d%*c", &nsz ) ) {
        memset( info, 0, sizeof(info) );
        for( int i=1; i<=nsz; ++i )
            scanf( "%s", info[i]+1 );
        int way; bool can;
        way = ways();
        if( way ) printf( "%d\n", way );
        else {
            if( arrive() )
                puts( "THE GAME IS A LIE" );
            else puts( "INCONCEIVABLE" );
        }
    }
}