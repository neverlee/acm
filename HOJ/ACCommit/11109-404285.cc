#include<cstdio>
char str[100];
int pre[2000], ind[2000], at[2000], node;
void Last( int pst, int ped, int ist, int ied ) {
    int k;
    if( pst>=ped||ist>=ied ) return;
    k = at[pre[pst]];
    Last( pst+1, pst+(k-ist)+1, ist, k );
    Last( pst+1+(k-ist), ped, k+1, ied );
    printf( "%8d", pre[pst] );
}
int main() {
    while( scanf( "%d", &node ), node ) {
        getchar(); gets( str );
        for( int i=0; i<node; ++i ) scanf( "%d", pre+i );
        getchar(); gets( str );
        for( int i=0; i<node; ++i ) {
            scanf( "%d", ind+i );
            at[ ind[i] ] = i;
        }
        puts( "Postorder Traversal:" );
        Last( 0, node, 0, node );
        putchar(\'\n\');
    }
}