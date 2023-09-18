#include<cstdio>
int gene[2][1000010], amount;
char flag[1000010];
char ic; int itmp;
inline int GetInt() {
    while( (ic=getchar()) < \'0\' );
    itmp = ic-\'0\';
    while( (ic=getchar()) >=\'0\' )
        itmp = itmp*10+ic-\'0\';
    return itmp;
}
int main() {
    int iTest; iTest=GetInt();
    while( iTest-- ) {
        scanf( "%d", &amount );
        for( int i=0; i<amount; ++i ) gene[0][i]=GetInt();
        for( int i=0; i<amount; ++i ) gene[1][i]=GetInt();
        int total=0;
        for( int i=0, s=0; i<amount; ++i ) {
            ++flag[ gene[0][i] ];
            if( flag[ gene[0][i] ] ) ++total;
            else --total;
            --flag[ gene[1][i] ];
            if( flag[ gene[1][i] ] ) ++total;
            else --total;
            if( total==0 ) {
                if( s ) putchar(\' \');
                printf( "%d-%d", s+1, i+1 );
                s=i+1;
            }
        }
        putchar(\'\n\');
    }
}
