#include <cstdio>
#include <cmath>

int p[10000]={2}, amount;
void init() {
    int ie;
    amount = 1;
    for( int i=3; i<100000; i+=2 ) {
        bool flag=1;
        ie = (int)sqrt((double)i);
        for( int j=0; p[j]<=ie; ++j )
            if( i%p[j]==0 ) {
                flag=0;
                break;
            }
        if( flag ) p[amount++] = i;
    }
}

int n, k, m;
__int64 ret;

int fact( int nk, int pi ) {
    int sum=0;
    while( nk>0 )
        sum += (nk/=pi);
    return sum;
}

void calu() {
    ret = 1;
    int hv;
    for( int i=0; p[i]<=n && i<amount; ++i ) {
        hv = fact( n, p[i] );
        hv -= fact( k, p[i] );
        hv -= fact( n-k, p[i] );
        while( hv-->0 ) {
            ret = ret*p[i]%m;
        }
    }
}

int main() {
    init();
    while( ~scanf( "%d%d%d", &n, &k ,&m ) ) {
        calu();
        printf( "%I64d\n", ret );
    }
}
