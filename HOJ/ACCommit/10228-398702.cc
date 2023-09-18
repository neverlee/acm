#include<cstdio>
#include<cstring>
short app[1050];
int s,m,h,t;
int main() {
    while( scanf( "%ld%ld", &s, &m), s) {
        memset( app, 0, m<<1 );
        putchar(\'.\');
        h=1;
        app[s]=1;
        for( int i=2; ; ++i ) {
            if( s<m ) s*=10;
            t = s/m;
            s = s%m;
            putchar( t+\'0\' );
            ++h;
            if( h%50==0 ) putchar(\'\n\');
            if( app[s]==0 ) {
                app[s]=i;
            } else {
                if( h%50 ) putchar(\'\n\');
                printf( "The last %ld digits repeat forever.\n", i-app[s] );
                break;
            }
            if( s==0 ) {
                if( h%50 ) putchar(\'\n\');
                printf("This expansion terminates.\n");
                break;
            }
        }
    }
}
