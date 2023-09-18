#include<cstdio>
#include<algorithm>
using namespace std;
struct Rect {
    int x1, x2, y1, y2;
    bool have;
    void Normal() {
        if( x1>x2 ) swap( x1, x2 );
        if( y1>y2 ) swap( y1, y2 );
    }
    bool IsIn( int x, int y ) {
        return ( x1<=x&&x<=x2 && y1<=y&&y<=y2 );
    }
    bool IsSame( Rect &r ) {
        return x1==r.x1 && x2==r.x2 && y1==r.y1 && y2==r.y2;
    }
} wnd[10010];
int amount, rct;
char str[100];
int main() {
    int Tcase; scanf( "%d", &Tcase );
    while( Tcase-- ) {
        scanf( "%d", &amount );
        rct=0;
        while( amount-- ) {
            scanf( "%s", str );
            if( str[2]==\'i\' ) {
                int x, y;
                scanf( "%d %d", &x, &y );
                for( int i=rct-1; i>=0; --i )
                if( wnd[i].have && wnd[i].IsIn( x, y ) ) {
                    wnd[rct]=wnd[i];
                    wnd[i].have=false;
                    ++rct;
                    break;
                }
            }else {
                scanf( "%d %d %d %d", &wnd[rct].x1, &wnd[rct].y1
                            , &wnd[rct].x2, &wnd[rct].y2 );
                wnd[rct].Normal();
                if( str[2]==\'o\' ) {
                    for( int i=0; i<rct; ++i )
                    if( wnd[i].have && wnd[i].IsSame( wnd[rct] ) ) {
                        wnd[i].have=false;
                        break;
                    }
                }else {
                    wnd[rct].have=1;
                    ++rct;
                }
            }
        }
        Rect *last;
        for( int i=rct-1; i>=0; --i )
        if( wnd[i].have ) {
            last = wnd+i;
            break;
        }
        printf( "%d %d %d %d\n", last->x1, last->y1, last->x2, last->y2 );
    }
}
