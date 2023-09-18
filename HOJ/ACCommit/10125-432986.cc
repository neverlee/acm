#include <cstdio>
#include <algorithm>
using namespace std;

int ay[2][26], amount;
int from( char *ss ) {
    int h, l;
    if( ss[0]<=\'9\' ) h=ss[0]-\'2\';
    else if( ss[0]==\'T\' ) h=8;
    else if( ss[0]==\'J\' ) h=9;
    else if( ss[0]==\'Q\' ) h=10;
    else if( ss[0]==\'K\' ) h=11;
    else h=12;
    if( ss[1]==\'H\' ) l=3;
    else if( ss[1]==\'S\' ) l=2;
    else if( ss[1]==\'D\' ) l=1;
    else l=0;
    return h*4+l;
}
void input() {
    char ss[3];
    scanf( "%d", &amount );
    for( int i=0; i<2; ++i ) {
        for( int j=0; j<amount; ++j ) {
            scanf( "%s", ss );
            ay[i][j] = from(ss);
            //printf( "%d ", ay[i][j] );
        }
        //puts("");
    }
    sort( ay[0], ay[0]+amount );
    sort( ay[1], ay[1]+amount );
}

void work() {
    int st, ed, ret;
    st=0; ed=amount-1;
    ret = 0;
    for( int i=0; i<amount; ++i ) {
        if( ay[1][i]<=ay[0][st] ) {
            --ed;
        }else {
            ++ret;
            ++st;
        }
    }
    printf( "%d\n", ret );
}

int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        input();
        work();
    }
}
