#include<cstdio>
#include<cstring>
int old[510], pos[510], byd[510], amount;
int nor[25010][2], inot;
void Input() {
    scanf( "%d", &amount );
    for( int i=0; i<amount; ++i ) {
        scanf( "%d", old+i );
        pos[ old[i] ] = i;
        byd[i]=i;
    }
    scanf( "%d", &inot );
    for( int i=0; i<inot; ++i )
        scanf( "%d%d", nor[i]+0, nor[i]+1 );
}
void Deal() {
    for( int i=0; i<inot; ++i ) {
        if( pos[ nor[i][0] ] < pos[ nor[i][1] ] ) {
            ++byd[ pos[ nor[i][0] ] ];
            --byd[ pos[ nor[i][1] ] ];
        }else {
            --byd[ pos[ nor[i][0] ] ];
            ++byd[ pos[ nor[i][1] ] ];
        }
    }
    int rct[510];
    memset( rct, -1, sizeof(rct) );
    for( int i=0; i<amount; ++i ) {
        if( rct[ byd[i] ] == -1 ) rct[ byd[i] ]=old[i];
        else {
            puts( "IMPOSSIBLE" );
            return;
        }
    }
    for( int i=0; i<amount; ++i ) {
        if( i!=0 ) putchar(\' \');
        if( rct[i]==-1 ) putchar(\'?\');
        else printf( "%d", rct[i] );
    }
    putchar(\'\n\');
}
int main() {
    int iTest; scanf( "%d", &iTest );
    while( iTest-- ) {
        Input();
        Deal();
    }
}
