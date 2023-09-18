#include <cstdio>

const int N = 200001;
int amount;
int x[N], y[N];

int main() {
    while( scanf( "%d", &amount ), amount ) {
        for( int i=0; i<amount; ++i )
            scanf( "%d%d", x+i, y+i );
        int s, o, mx, my;
        mx = x[amount/2]; my = y[amount/2];
        s = o = 0;
        for( int i=0; i<amount; ++i )
        if( x[i]!=mx && y[i]!=my ) {
            if( x[i]>mx && y[i]>my || x[i]<mx && y[i]<my ) ++s;
            else ++o;
        }
        printf( "%d %d\n", s, o );
    }
}
