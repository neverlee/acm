#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

const int N = 1010;
int hv[26], p[26], line;
char ss[N];
int main() {
    scanf( "%d%*c", &line );
    while( line-- ) {
        gets( ss );
        for( int i=0; ss[i]; ++i )
            if( isalpha( ss[i] ) ) {
                if( islower(ss[i] ) ) ss[i]-=32;
                ++hv[ss[i]-\'A\'];
            }
    }
    for( int i=0; i<26; ++i ) p[i] = i;
    for( int i=0; i<26; ++i )
        for( int j=i+1; j<26; ++j )
            if( hv[p[i]]<hv[p[j]] || hv[p[i]]==hv[p[j]]&&p[i]>p[j] )
                std::swap( p[i], p[j] );
    for( int i=0; i<26; ++i )
        if( hv[p[i]] )
            printf( "%c %d\n", \'A\'+p[i], hv[p[i]] );
}
