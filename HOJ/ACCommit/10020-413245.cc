#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef pair<unsigned, int> Pui;
struct CmpPui{
    bool operator() ( const Pui &a, const Pui &b ) const {
        return a.second>b.second;
    }
};

struct Post{
    int x, y;
    void set( int xx, int yy ) { x=xx; y=yy; }
    Post operator+( const Post &pb ) {
        Post pc;
        pc.set( x+pb.x, y+pb.y );
        return pc;
    }
    Post operator-( const Post &pb ) {
        Post pc;
        pc.set( x-pb.x, y-pb.y );
        return pc;
    }
    friend bool operator==( const Post &pa, const Post &pb ) {
        return pa.x==pb.x&&pa.y==pb.y;
    }
    int fs() { return x+y-2; }
};

int xll, yll, len;
bool hole[22][22];

vector<Post> drt;
void init_drt() {
    drt.resize(4);
    drt[0].set( 0, -1 );
    drt[1].set( -1, 0 );
    drt[2].set( 0, 1 );
    drt[3].set( 1, 0 );
}

struct Snack{
    Post head;
    int tail;
    int f;
    Pui get_pui() {
        Pui ui;
        ui.second = f;
        ui.first=0;
        ui.first |= head.x<<24;
        ui.first |= head.y<<16;
        ui.first |= tail;
        return ui;
    }
    void from_pui( Pui &ui ) {
        f = ui.second;
        head.x = (ui.first>>24)&0xff;
        head.y = (ui.first>>16)&0xff;
        tail = ui.first&0xffff;
    }
    bool can_next( int ni ) {
        Post pre, nxt, rst;
        rst = head+drt[ni];
        if( hole[rst.x][rst.y]==0 ) return false;
        pre = head;
        int i;
        for( i=len*2-4; i>=0; i-=2 ) {
            nxt = pre-drt[(tail>>i)&3];
            if( rst==nxt ) return false;
            pre = nxt;
        }
        return true;
    }
    void move( int ni ) {
        int g;
        g = f-head.fs();
        head = head+drt[ni];
        tail = (tail>>2) | (ni<<(len*2-4));
        f = g+head.fs()+1;
    }
}start;

int ret;
void Astar() {
    priority_queue<Pui, vector<Pui>, CmpPui> open;
    map<unsigned, int> close;
    start.f = start.head.fs();
    Pui one, two;
    one = start.get_pui();
    open.push( one );
    int di;
    map<unsigned, int>::iterator it;
    while( !open.empty() ) {
        one = open.top();
        while( !open.empty() && one==open.top() ) open.pop();
        it = close.find( one.first );
        if( it==close.end() ) close.insert( one );
        else if( it->second>one.second ) it->second = one.second;
        else continue;
        for( di=0; di<drt.size(); ++di ) {
            Snack cur;
            cur.from_pui( one );
            if( cur.can_next( di ) ) {
                cur.move(di);
                two = cur.get_pui();
                it = close.find( two.first );
                if( it==close.end() || it->second>two.second ) {
                    open.push( two );
                    if( cur.head.x==1 && cur.head.y==1 ) {
                        ret = cur.f;
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    init_drt();
    int icase;
    for( icase=1; scanf( "%d%d%d", &xll, &yll, &len ), xll&&yll&&len; ++icase ) {
        int i, j;
        scanf( "%d%d", &start.head.x, &start.head.y );
        Post pa, pb;
        pa = start.head;
        start.tail = 0;
        for( i=1; i<len; ++i ) {
            scanf( "%d%d", &pb.x, &pb.y );
            for( j=0; j<drt.size(); ++j ) {
                if( pb+drt[j]==pa ) {
                    start.tail = (start.tail<<2)+j;
                    pa = pb;
                    break;
                }
            }
        }
        memset( hole, 1, sizeof(hole) );
        for( i=0; i<=xll+1; ++i )
            hole[i][0] = hole[i][yll+1] = 0;
        for( i=0; i<=yll+1; ++i )
            hole[0][i] = hole[xll+1][i] = 0;
        int amount;
        scanf( "%d", &amount );
        while( amount-- ) {
            scanf( "%d%d", &pa.x, &pa.y );
            hole[pa.x][pa.y] = 0;
        }
        ret = -1;
        if( start.head.x==1 && start.head.y==1 ) {
            ret=0;
        }else Astar();
        printf( "Case %d: %d\n", icase, ret );
    }
}