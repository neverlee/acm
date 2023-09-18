#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100;

struct Rect {
    int ax, ay, bx, by;
    unsigned val;
    void build( int cx, int cy, int dx, int dy ) {
        ax = cx; ay = cy; bx = dx; by = dy;
    }
    void input() {
        scanf( "%d%d%d%d%u", &ax, &ay, &bx, &by, &val );
        ++bx; ++by;
    }
    bool is_normal() {
        return ax<bx&&ay<by;
    }
    Rect &operator=( Rect &r ) {
        ax = r.ax; ay = r.ay; bx = r.bx; by = r.by; val = r.val;
    }
};

Rect f[2][N], *fa, *fb;
int len;

int imax( int a, int b ) { return a>b?a:b; }
int imin( int a, int b ) { return a<b?a:b; }
void getbuild( unsigned val, int &nk ) {
    if( fb[nk].is_normal() ) {
        fb[nk].val = val;
        ++nk;
    }
}
void find( Rect &src, Rect &tag, int &h ) {
    if( tag.by<=src.ay || src.by<=tag.ay 
            || tag.bx<=src.ax || src.bx<=tag.ax ) {
        fb[h++] = src;
        return;
    }
    fb[h].build( src.ax, src.ay, imin(src.bx,tag.ax), src.by );
    getbuild( src.val, h );
    fb[h].build( imax(src.ax,tag.ax), src.ay, src.bx, imin(src.by,tag.ay) );
    getbuild( src.val, h );
    fb[h].build( imax(src.ax,tag.bx), imax(src.ay,tag.ay), src.bx, src.by );
    getbuild( src.val, h );
    fb[h].build( imax(src.ax,tag.ax), imax(src.ay,tag.by), imin(src.bx,tag.bx), src.by );
    getbuild( src.val, h );
}
int main() {
    int amount; scanf( "%d", &amount );
    if( amount==0 ) {
        puts("0");
        return 0;
    }
    fa = f[0]; fb = f[1];
    len = 0;
    while( amount-- ) {
        fb[0].input();
        int k=1;
        for( int i=0; i<len; ++i )
            find( fa[i], fb[0], k );
        len = k;
        swap( fa, fb );
    }
    __int64 ret = 0;
    for( int i=0; i<len; ++i ) {
        ret += (__int64)(fa[i].bx-fa[i].ax)*
                (fa[i].by-fa[i].ay)*fa[i].val;
    }
    printf( "%I64d", ret );
}




