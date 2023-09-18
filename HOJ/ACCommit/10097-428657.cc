#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool done[110][12];
int paut[110][12];

struct Score{
    int cid, pn, paut;
    bool operator<( const Score &s ) const {
        return pn>s.pn || (pn==s.pn&&paut<s.paut)
            || (pn==s.pn&&paut==s.paut&&cid<s.cid);
    }
}sces[110];

void input() {
    memset( done, 0, sizeof(done) );
    memset( paut, 0, sizeof(paut) );
    int cid, pid, tm; char on;
    while( ~scanf( "%d %d %d %c", &cid, &pid, &tm, &on ) ) {
        //printf( "-%d %d %d %c\n", cid, pid, tm, on );
        done[cid][0] = 1;
        if( !done[cid][pid] ) {
            if( on==\'C\' ) {
                paut[cid][pid] += tm;
                done[cid][pid] = 1;
            }else if( on==\'I\' )
                paut[cid][pid] += 20;
        }
    }
}

int k;
void from() {
    k = 0;
    for( int i=1; i<=100; ++i )
    if( done[i][0] ) {
        sces[k].cid = i;
        sces[k].pn = 0;
        sces[k].paut = 0;
        for( int j=1; j<=10; ++j )
        if( done[i][j] ) {
            ++sces[k].pn;
            sces[k].paut += paut[i][j];
        }
        ++k;
    }
    sort( sces, sces+k );
    for( int i=0; i<k; ++i )
        printf( "%d %d %d\n", sces[i].cid, sces[i].pn, sces[i].paut );
}

int main() {
    input();
    from();
}
