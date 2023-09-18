#include <cstdio>

int amount, ay[50010];

void get() {
    int ret=0;
    for( int i=0; i<amount; ++i ) {
        if( ay[i]>=ay[i+1] ) {
            printf( "%d\n", i+1 );
            while( ay[i]>ay[i+1] && i<amount ) ++i;
        }
    }
}

int main() {
    scanf( "%d", &amount );
    for( int i=0; i<amount; ++i )
        scanf( "%d", ay+i );
    ay[amount] = ay[amount-1];
    get();
}    
