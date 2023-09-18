#include<cstdio>
#include<cstring>
int dt[400000], amount;
int n, dk;
char o; int da, db;
int is, it;
void insert( int pos, int ins, int ine ) {
    if( ins>it || ine<is ) return;
    if( is<=ins && ine<=it ) {
        ++dt[pos];
        return;
    }
    insert( pos*2, ins, (ins+ine)/2 );
    insert( pos*2+1, (ins+ine)/2+1, ine );
}
void work( int s, int t ) {
    is = s; it = t;
    if( is<=it )
        insert( 1, 1, dk );
}
int min( int a, int b ) { return a<b?a:b; }
int max( int a, int b ) { return a>b?a:b; }
int main() {
    while( EOF != scanf( "%d%d", &amount, &n ) ) {
        for( dk=1; dk<amount; dk<<=1 );
        memset( dt, 0, sizeof(int)*(dk*2+3) );
        while( n-- ) {
            scanf( " %c", &o );
            if( o==\'Q\' ) {
                scanf( "%d", &da );
                da = dk + da - 1;
                int sum=0;
                for( ; da>0; da>>=1 ) sum += dt[da];
                printf( "%d\n", sum );
            }else {
                scanf( "%d%d", &da, &db );
                dt[1] += db/amount;
                db %= amount;
                if( o==\'C\' ) {
                    work( da, min( amount, da+db-1 ) );
                    work( 1, da+db-amount-1 );
                }else {
                    work( max( 1, da-db+1 ), da );
                    work( amount-(db-da-1), amount );
                }
            }
        }
    }
}