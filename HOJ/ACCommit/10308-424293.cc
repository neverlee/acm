#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int SIZE = 3010;

struct Pro{
    int ft, p;
    bool operator< ( const Pro &pb ) const {
        return ft>pb.ft;
    }
}plm[SIZE];

struct Cmp{
    bool operator() ( const Pro &pa, const Pro &pb ) const {
        return pa.p<pb.p;
    }
};

int amount, penalty;

void init() {
    scanf( "%d", &amount );
    penalty = 0;
    for( int i=0; i<amount; ++i ) {
        scanf( "%d%d", &plm[i].ft, &plm[i].p );
        penalty += plm[i].p;
    }
    sort( plm, plm+amount );
}

void work() {
    priority_queue< Pro, vector<Pro>, Cmp > qp;
    for( int i=0,k=amount; k>0; --k ) {
        while( plm[i].ft>=k && i<amount ) {
            qp.push( plm[i] );
            ++i;
        }
        if( !qp.empty() ) {
            penalty -= qp.top().p;
            qp.pop();
        }
    }
    printf( "%d\n", penalty );
}

int main() {
    int T; scanf( "%d", &T );
    for( int i=1; i<=T; ++i ) {
        printf( "Case %d:\n", i );
        init();
        work();
        if( i!=T ) putchar(\'\n\');
    }
}

