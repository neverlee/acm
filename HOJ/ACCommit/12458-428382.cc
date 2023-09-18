#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std;

const int SIZE = 310;
int mtx[SIZE][SIZE];
int amount;
int XX( int x ) { return x*x; }

struct Pad{
    int frq, x, y, r;
    bool intersect( Pad &p ) {
        int dist = XX( x-p.x ) + XX( y-p.y );
        return dist<XX(r+p.r);
    }
}pads[310];

void init() {
    scanf( "%d", &amount );
    int a, c, d, e;
    char str[10];
    for( int i=0; i<amount; ++i ) {
        memset( str, 0, sizeof(str) );
        scanf( "%d.%s%d%d%d", &a, str, &c, &d, &e );
        for( int k=0; k<3; ++k ) {
            a = a*10;
            if( isdigit(str[k]) )
                a += (str[k]-\'0\');
        }
        pads[i].frq = a;
        pads[i].x = c;
        pads[i].y = d;
        pads[i].r = e;
    }
    for( int i=0; i<amount; ++i ) {
        if( pads[i].frq == 400000 )
            swap( pads[0], pads[i] );
        if( pads[i].frq == 789000 )
            swap( pads[amount-1], pads[i] );
    }
    memset( mtx, 0, sizeof(mtx) );
    for( int i=0; i<amount; ++i )
        for( int j=0; j<amount; ++j)
            if( i!=j ) {
                if( pads[i].intersect( pads[j] ) && pads[i].frq<pads[j].frq )
                    mtx[i][j] = 1;
            }
}

int start, end;
const int INF = 0x0fffffff;
int path[SIZE];
int flow[SIZE];
int bfs(){
    queue<int> q;
    int i;
    memset( path, -1, sizeof(path) );
    memset( flow, 0, sizeof(flow) );
    path[start]=0,flow[start]=INF;

    q.push(start);
    while(!q.empty()) {
        int top=q.front();
        q.pop();
        if(top==end) break;
        for( i=1; i<amount; ++i ) {
            if( path[i]==-1 && mtx[top][i]) {
                flow[i]=flow[top]<mtx[top][i] ? flow[top]:mtx[top][i];
                q.push(i);
                path[i]=top;
            }
        }
    }
    if(path[end]==-1) return -1;
    return flow[end];
}

int Edmonds_Karp() {
    int maxflow=0,step,cur,pre;
    start=0; end=amount-1;
    while( ( step=bfs() ) != -1) {
        maxflow += step;
        cur=end;
        while(cur != start) {
            pre=path[cur];
            mtx[pre][cur] -= step;
            mtx[cur][pre] += step;
            cur=pre;
        }
    }
    return maxflow;
}

int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        init();
        int n = Edmonds_Karp();
        if( n>=2 ) puts( "Game is VALID" );
        else puts( "Game is NOT VALID" );
    }
}
