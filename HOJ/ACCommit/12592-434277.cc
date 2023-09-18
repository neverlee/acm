#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define abs(n) ((n)>0?(n):-(n))

char src[][20] = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
int x[26], y[26];

void init() {
    for( int i=0; i<3; ++i )
        for( int j=0; src[i][j]; ++j ) {
            char t=src[i][j]-\'a\';
            x[t]=i; y[t]=j;
        }
}

char sa[10010], sb[10][10010];
int cpn[10], pt[10];

bool cmp( const int &a, const int &b ) {
    return cpn[a]<cpn[b]
        || cpn[a]==cpn[b]&&strcmp(sb[a],sb[b])<0;
}

int cmp_str( char *sb ) {
    int sum=0;
    char a, b;
    for( int i=0; sa[i]; ++i ) {
        a=sa[i]-\'a\'; b=sb[i]-\'a\';
        sum += abs( x[a]-x[b] ) + abs( y[a]-y[b] );
    }
    return sum;
}

int main() {
    int T; scanf( "%d", &T );
    init();
    while( T-- ) {
        int n;
        scanf( "%s%d", sa, &n );
        for( int i=0; i<n; ++i ) {
            scanf( "%s", sb[i] );
            cpn[i] = cmp_str( sb[i] );
            pt[i] = i;
        }
        sort( pt, pt+n, cmp );
        for( int i=0; i<n; ++i )
            printf( "%s %d\n", sb[pt[i]], cpn[pt[i]] );
    }
}

