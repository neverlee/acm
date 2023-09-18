#include<cstdio>
int test, son, mum, st, ed;
int main() {
    scanf( "%d", &test );
    for( int icase=1; icase<=test; ++icase ) {
        scanf( "%d %d %d %d", &son, &mum, &st, &ed );
        printf( "Problem set %d: %d / %d, base 7 digits %d through %d: "
                , icase, son, mum, st, ed );
        son%=mum;
        for( int i=0; i<st; ++i )
            son=son*7%mum;
        for( int i=st; i<=ed; ++i ) {
            son*=7;
            printf( "%d", son/mum );
            son%=mum;
        }
        putchar(\'\n\');
    }
}