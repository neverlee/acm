#include <cstdio>

int kn, b, g;
char s[400];

int main() {
    gets( s );
    sscanf( s, "%d", &kn );
    while( kn-- ) {
        b = g = 0;
        gets(s);
        for( int i=0; s[i]; ++i ) {
            if( s[i]==\'b\' || s[i]==\'B\' ) ++b;
            if( s[i]==\'g\' || s[i]==\'G\' ) ++g;
        }
        printf( "%s is ", s );
        if( b<g ) puts( "GOOD" );
        if( b>g ) puts( "A BADDY" );
        if( b==g ) puts( "NEUTRAL" );
    }
}
