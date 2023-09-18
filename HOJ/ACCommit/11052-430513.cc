#include <cstdio>

char s[300];

int main() {
    while( gets(s) ) {
        if( s[0]==\'#\' ) break;
        int sum=0;
        for( int i=0; s[i]; ++i )
            if( s[i]>=\'A\' && s[i]<=\'Z\' )
                sum += (i+1)*(s[i]-\'A\'+1);
        printf( "%d\n", sum );
    }
}
