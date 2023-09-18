#include<cstdio>
#include<cstring>
char str[200];
int buy[1001], sell[1001];
int ai, bi, si, opn;
int sp, bp;
int IMax( int a, int b ) { return a>b?a:b; }
int IMin( int a, int b ) { return a<b?a:b; }
void Output() {
    if( ai>0&&ai<=1000 ) printf( "%d ", ai );
    else printf( "- ");
    if( bi>0&&bi<=1000 ) printf( "%d ", bi );
    else printf( "- ");
    if( si>0&&si<=1000 ) printf( "%d\n", si );
    else printf( "-\n");
}
void Business() {
    while( sp<=bp ) {
        if( sell[sp] < buy[bp] ) {
            buy[bp]-=sell[sp];
            sell[sp]=0;
            si=sp;
        }else {
            sell[sp]-=buy[bp];
            buy[bp]=0;
            si=sp;
        }
        while( sell[sp]==0 && sp<=1000 ) ++sp;
        while( buy[bp]==0 && bp>0 ) --bp;
    }
    ai=sp;
    bi=bp;
}
int main() {
    int iTest; scanf( "%d", &iTest );
    while( iTest-- ) {
        scanf( "%d%*c", &opn );
        memset( sell, 0, sizeof(sell) );
        memset( buy, 0, sizeof(buy) );
        ai=bi=si=-1;
        int num, price;
        sp=1001; bp=0;
        while( opn-- ) {
            gets( str );
            sscanf( str+4, "%d%*s%*s%d", &num, &price );
            if( str[0]==\'s\' ) {
                sell[price]+=num;
                if( price<sp ) {
                    sp=price;
                    ai=price;
                }
            }else {
                buy[price]+=num;
                if( price>bp ) {
                    bp=price;
                    bi=price;
                }
            }
            Business();
            Output();
        }
    }
}
