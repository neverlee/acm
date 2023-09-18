#include<cstdio>
#include<cstring>
int iTeam, ia, ib, iall, total;
int dp[10010];
int IMin( int a, int b ) { return a<b?a:b; }
int IMax( int a, int b ) { return a>b?a:b; }
void Dp() {
    dp[0]=0;
    total = 0;
    iall=ia+ib;
    int n, da, db, lene=0, lens;
    while( iTeam-- ) {
        scanf( "%ld %ld %ld", &n, &da, &db );
        lens = IMax( 0, total-ib );
        for( int i=lene; i>=lens; --i )
        if( dp[i]!=-1 ) {
            int s, e, t;
            s=IMax( 0, n+total-iall );
            e=IMin( ia-i, n );
            for( int j=e; j>s; --j ) {
                t=dp[i]+j*da+(n-j)*db;
                if( dp[i+j]==-1 || dp[i+j]>t )
                    dp[i+j]=t;
            }
            dp[i]=dp[i]+s*da+(n-s)*db;
        }
        lene+=IMin( ia-lene, n );
        total+=n;
    }
    n=dp[lene];
    int last=IMax( 0, total-ib );
    for( int i=lene; i>=last; i-- )
    if( dp[i]!=-1 )
        n=IMin( dp[i], n );
    printf( "%ld\n", n );
}
int main() {
    while( scanf( "%ld %ld %ld", &iTeam, &ia, &ib ) ,iTeam ) {
        memset( dp, -1, 4*(ia+10) );
        Dp();
    }
}
