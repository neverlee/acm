#include <cstdio>
#include <cstring>

char str[300];
bool check() {
    int s=0;
    for( int i=0; str[i]; ++i ) {
        if( str[i]>=\'p\' && str[i]<=\'z\' ) ++s;
        else if( strchr( "CDEI", str[i] ) ) --s;
        else if( str[i]!=\'N\' ) return 0;
        if( s>1 ) return 0;
    }
    if( s==1 ) return 1;
}

int main() {
    while( gets( str ) ) {
        if( check() ) puts( "YES" );
        else puts( "NO" );
    }
}