#include <cstdio>
#include <cstring>

const int SIZE = 1030;
int f[SIZE], isz, ied;
void init( int n ) {
    isz = 1;
    while( isz<n ) isz<<=1;
    ied = isz*2;
    for( int i=isz; i<ied; ++i ) f[i] = 1;
    for( int i=isz-1; i>0; --i )
        f[i] = f[i+i]+f[i+i+1];
}

void change( int n ) {
    int k = n+isz;
    while( k>0 ) {
        --f[k];
        k/=2;
    }
}

int find( int nk ) {
    int p, pp;
    for( p=1; nk>0&&p<isz; ) {
        pp = p+p;
        if( f[pp]< nk ) {
            nk-=f[pp];
            p = pp+1;
        }else p = pp;
    }
    while( p<isz ) {
        pp = p+p;
        if( f[pp+1] ) p = pp+1;
        else p = pp;
    }
    return p-isz;
}

int amount, ay[SIZE/2];

int main() {
    while( scanf( "%d", &amount ), amount ) {
        init(amount);
        for( int i=1; i<=amount; ++i ) {
            int t, k;
            scanf( "%d", &t );
            ++t;
            k = find(t);
            ay[k] = i;
            change(k);
        }
        printf( "%d", ay[0] );
        for( int i=1; i<amount; ++i )
            printf( ",%d", ay[i] );
        puts("");
    }
}
