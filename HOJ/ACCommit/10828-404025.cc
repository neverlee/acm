#include<cstdio>
int M, N;
char ast[25][20], *ps[25], *pt[25];
int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d %d", &M, &N );
        for( int i=0; i<M; ++i ) {
            scanf( "%s", ast[i] );
            ps[i]=ast[i];
            pt[i]=NULL;
        }
        int a,b;
        while( N-- ) {
            scanf( "%d %d", &a, &b );
            --a; --b;
            pt[b]=ps[a];
            ps[a]=NULL;
        }
        for( int i=0, j=0; i<M; ++i ) {
            if( i ) putchar(\' \');
            if( pt[i]==NULL ) {
                while( ps[j]==NULL ) ++j;
                printf( "%s", ps[j] );
                ++j;
            }else printf( "%s", pt[i] );
        }
        putchar(\'\n\');
    }
}
