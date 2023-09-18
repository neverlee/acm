#include <cstdio>
#include <cstring>

bool f[0xfffff];

int amount, ask, lsz;
int left, right;

int getint() {
    char c;
    while( (c=getchar())<\'0\' );
    int k=c-\'0\';
    while( (c=getchar())>=\'0\' )
        k = k*10+c-\'0\';
    return k;
}

void init() {
    for( lsz=1; lsz<amount; lsz<<=1 );
    for( int i=0; i<amount; ++i ) f[i+lsz] = 1;
    for( int i=amount; i<lsz; ++i ) f[lsz+i] = 0;
    for( int i=lsz-1; i>0; --i )
        f[i] = f[2*i]||f[2*i+1];
}

void kill( int n, int l, int r ) {
    if( left<=l && r<=right )
        f[n] = 0;
    else if( r<=left || l>=right )
        return;
    else {
        int d=(l+r)/2;
        kill( n+n, l, d );
        kill( n+n+1, d, r );
    }
    if( !f[n+n] && !f[n+n+1] )
        f[n] = 0;
}

int ret, fdn;
void find_left( int n, int l, int r ) {
    if( ret!=-1 ) return;
    if( n>=lsz ) {
        if( f[n] && l<=fdn ) ret = n-lsz+1;
        return;
    }
    int m = (l+r)/2;
    if( fdn>=m && f[n+n+1] )
        find_left( n+n+1, m, r );
    if( f[n+n] )
        find_left( n+n, l, m );
}
void find_right( int n, int l, int r ) {
    if( ret!=-1 ) return;
    if( n>=lsz ) {
        if( f[n] && l>=fdn ) ret = n-lsz+1;
        return;
    }
    int m = (l+r)/2;
    if( fdn<m && f[n+n] )
        find_right( n+n, l, m );
    if( f[n+n+1] )
        find_right( n+n+1, m, r );
}

int main() {
    while( scanf( "%d%d", &amount, &ask ), amount ) {
        init();
        while( ask-- ) {
            left=getint(); right=getint();
            --left;
            kill( 1, 0, lsz );
            ret=-1; fdn = left-1;
            find_left( 1, 0, lsz );
            if( ret==-1 ) printf("* ");
            else printf( "%d ", ret );
            ret=-1; fdn = right;
            find_right( 1, 0, lsz );
            if( ret==-1 ) printf("*\n");
            else printf( "%d\n", ret );
        }
        puts("-");
    }
}
