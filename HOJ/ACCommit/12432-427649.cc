#include <cstdio>

struct Rect {
    int ax, ay, bx, by;
    void build( int cx, int cy, int dx, int dy ) {
        ax = cx; ay = cy; bx = dx; by = dy;
    }
    void input() {
        scanf( "%d%d%d%d", &ax, &ay, &bx, &by );
    }
    void output() {
        printf( "%d %d %d %d\n", ax, ay, bx, by );
    }
    bool is_normal() {
        return ax<bx&&ay<by;
    }
    Rect &operator=( Rect &r ) {
        ax = r.ax; ay = r.ay;
        bx = r.bx; by = r.by;
    }
};

int imax( int a, int b ) { return a>b?a:b; }
int imin( int a, int b ) { return a<b?a:b; }

Rect src, tag, get[4];
int h=0;

void getbuild() {
    if( get[h].is_normal() )
        ++h;
}
void find() {
    get[h].build( src.ax, src.ay, imin(src.bx,tag.ax), src.by );
    getbuild();
    get[h].build( imax(src.ax,tag.ax), src.ay, src.bx, imin(src.by,tag.ay) );
    getbuild();
    get[h].build( imax(src.ax,tag.bx), imax(src.ay,tag.ay), src.bx, src.by );
    getbuild();
    get[h].build( imax(src.ax,tag.ax), imax(src.ay,tag.by), imin(src.bx,tag.bx), src.by );
    getbuild();
}
int main() {
    src.input();
    tag.input();
    if( !( tag.by<=src.ay || src.by<=tag.ay ) 
            && !( tag.bx<=src.ax || src.bx<=tag.ax ) ) {
        find();
        printf( "%d\n", h );
        for( int i=0; i<h; ++i ) {
            get[i].output();
        }
    }else {
        puts("1");
        src.output();
    }
}
