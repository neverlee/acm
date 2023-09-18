#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

bool mut[40][40];
map<int, int> ref;
int id;

void init() {
    int link;
    id = 0;
    scanf( "%d", &link );
    int x, y;
    while( link-- ) {
        scanf( "%d%d", &x, &y );
        if( ref.find(x)==ref.end() )
            ref[x] = id++;
        if( ref.find(y)==ref.end() )
            ref[y] = id++;
        mut[ref[x]][ref[y]] = 1;
        mut[ref[y]][ref[x]] = 1;
    }
}

#define G(p,l) ((p)|((l)<<16))
void bfs( int fs, int lmt ) {
    queue<int> qi;
    bool visit[40]={0};
    visit[fs] = 1;
    qi.push( G(fs,lmt) );
    int can=1;
    while( !qi.empty() ) {
        int p, l;
        p = qi.front()&0xffff;
        l = qi.front()>>16;
        qi.pop();
        if( l==0 ) continue;
        for( int i=0; i<id; ++i )
        if( mut[p][i]==1 && visit[i]==0 ) {
            visit[i] = 1;
            ++can;
            qi.push( G(i,l-1) );
        }
    }
    printf( "%d\n", id-can );
}

int main() {
    init();
    int fs, lmt;
    while( ~scanf( "%d%d", &fs, &lmt ), fs&&lmt )
        bfs( ref[fs], lmt );
}
