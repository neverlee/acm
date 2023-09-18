#include <cstdio>
#include <cstring>

const int SIZE = 1000010;
bool can[SIZE];
int n, lmt, que, mask;

void inc( int &n ) {
    ++n;
    for( int i=0; ((n>>i)&0xf)>9; i+=4 )
        n += (6<<i);
}

void init() {
    lmt=10;
    for( int i=1; i<n; ++i ) {
        lmt*=10;
        putchar(\'0\');
    }
    for( int i=0; i<lmt; ++i ) can[i]=1;
    que = 0;
    mask = (1<<(4*n)) -1;
}

int fromhex( int n ) {
    int in=0;
    for( int k=1; n; k*=10, n>>=4 )
        in += (n&0xf)*k;
    return in;
}

void run() {
    int ie=lmt/10*9;
    for( int i=0, in=0; in<ie; ++in, inc(i) )
    if( can[in] ) {
        int m, k;
        m = mask>>4;
        for( k=4; (que&m)^(i>>k); k+=4, m>>=4 );
        for( int p=k-4; p>=0; p-=4 )
            putchar( ((i>>p)&0xf)+\'0\' );
        long long ll;
        ll = (((long long)que)<<k) | i;
        for( int p=0; p<k; p+=4 ) {
            int t = fromhex( (ll>>p)&mask );
            can[ t ] = 0;
        }
        que = ll&mask;
    }
    putchar(\'9\');
    for( int i=1; i<n; ++i )
        putchar(\'0\');
    putchar(\'\n\');
}

int main() {
    while( scanf( "%d", &n ), n ) {
        init();
        run();
    }
}