#include <cstdio>

int h, u, d, f;

int main() {
    while( scanf( "%d%d%d%d", &h, &u, &d, &f ), h ) {
        f = u*f;
        h*=100; u*=100; d*=100;
        int rct=0, id, ui;
        ui = u;
        for( id=1; ; ++id ) {
            rct += ui;
            if( rct>h ) break;
            ui -= f; if( ui<0 ) ui=0;
            rct -= d;
            if( rct<0 ) break;
        }
        if( rct>0 ) printf( "success on day %d\n", id );
        else printf( "failure on day %d\n", id );
    }
}
