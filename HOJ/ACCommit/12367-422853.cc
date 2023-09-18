#include <cstdio>
#include <cstring>

const int SIZE = 110;

char pat[SIZE], str[SIZE];
bool f[SIZE][SIZE];
bool check() {
    memset( f, 0, sizeof(f) );
    f[0][0] = 1;
    if( pat[1]==\'*\' ) f[1][0] = 1;
    int lp, ls;
    lp = strlen( pat+1 );
    ls = strlen( str+1 );
    for( int i=1; i<=lp; ++i )
        for( int j=1; j<=ls; ++j ) {
            if( f[i-1][j-1] && pat[i]==str[j] )
                f[i][j] = 1;
            if( pat[i]==\'*\' && ( f[i][j-1] || f[i-1][j] || f[i-1][j-1] ) )
                f[i][j] = 1;
        }
    return f[lp][ls];
}



int main() {
    while( EOF != scanf( "%s", pat+1 ) ) {
        int n;
        scanf( "%d", &n );
        while( n-- ) {
            scanf( "%s", str+1 );
            if( check() )
                puts( str+1 );
        }
    }
}