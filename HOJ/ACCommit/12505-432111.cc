#include <cstdio>
#include <cstring>
#include <cctype>

char ss[1010];
int cnt[26], len, mx, mc;

int main() {
    int T;
    scanf( "%d%*c", &T );
    while( T-- ) {
        gets( ss );
        memset( cnt, 0, sizeof(cnt) );
        len = strlen( ss );
        for( int i=0; i<len; ++i )
            if( isupper( ss[i] ) )
                ++cnt[ ss[i]-\'A\' ];
        mx = 0; mc = 0;
        for( int i=0; i<26; ++i ) mx = cnt[i]>=cnt[mx]?i:mx;
        for( int i=0; i<26; ++i ) if( cnt[i]==cnt[mx] ) ++mc;
        if( mc>1 ) puts( "NOT POSSIBLE" );
        else {
            mx = (mx+22)%26;
            printf( "%d ", mx );
            for( int i=0; i<len; ++i )
            if( isupper(ss[i]) ) {
                char cc;
                cc = ss[i]-mx;
                if( cc<\'A\' ) cc+=26;
                putchar( cc );
            }else putchar( ss[i] );
            putchar(\'\n\');
        }
    }
}

