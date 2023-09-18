#include <cstdio>
#include <cstring>

int high, width;
char str[420];

int rx, ry, nx, ny;
char get( int x, int y ) {
    return str[x*width+y]==\'1\';
}
void gonext() {
    ++nx; --ny;
    if( nx>=high || ny<0 ) {
        if( ry!=width-1 ) ++ry;
        else ++rx;
        nx = rx; ny = ry;
    }
}

void done() {
    char o=1;
    while( nx<high && ny<width ) {
        o = 0;
        for( int i=0; i<7; ++i ) {
            //printf( " (%d,%d) ", nx, ny );
            o = (o<<1)+get(nx, ny);
            gonext();
        }
        if( o!=0 ) putchar(o);
        else break;
    }
    putchar(\'\n\');
}

int main() {
    while( scanf( "%d", &width ), width ) {
        scanf( "%s", str );
        high = strlen(str)/width;
        rx = ry = 0;
        nx = ny = 0;
        done();
    }
}