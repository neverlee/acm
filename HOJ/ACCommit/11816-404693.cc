#include<cstdio>
struct Rect {
    int r1, c1, r2, c2;
    void Normal() {
        r2+=r1;
        c2+=c1;
    }
    bool IsIn( int r, int c ) {
        return (r1<=r&&r<r2&&c1<=c&&c<c2);
    }
};
Rect wnd[110];
int iwnd;
int main() {
    for( int iTest=1; scanf( "%d", &iwnd ), iwnd; ++iTest ) {
        for( int i=0; i<iwnd; ++i ) {
            scanf( "%d%d%d%d", &wnd[i].r1, &wnd[i].c1, &wnd[i].c2
                    , &wnd[i].r2 );
            wnd[i].Normal();
        }
        printf( "Desktop %d:\n", iTest );
        int r, c, nd, st;
        scanf( "%d", &nd );
        while( nd-- ) {
            scanf( "%d%d", &r, &c );
            for( st=iwnd-1; st>=0; --st )
            if( wnd[st].IsIn( r, c ) ) {
                printf( "window %d\n", st+1 );
                break;
            }
            if( st<0 ) puts( "background" );
        }
    }
}