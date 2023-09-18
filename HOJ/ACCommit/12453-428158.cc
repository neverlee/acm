#include <cstdio>
#include <cstring>

int cnt[4];
char str[400];

char attp( char *p ) {
    const char tp[4][4] = { "yes", "y", "no", "n" };
    for( int i=0; i<4; ++i )
        if( strcmp( p, tp[i] ) == 0 )
            return i/2;
    return -1;
}
void deal() {
    char *p, c;
    p = strtok( str, " " );
    int h=0, ct=0;
    while( p ) {
        c = attp( p );
        if( c>=0 ) ++ct;
        if( c==0 ) break;
        else if( c==1 ) ++h;
        p = strtok( NULL, " " );
    }
    if( ct==0 ) ++cnt[3];
    else if( h==5 ) ++cnt[2];
    else if( h>0 ) ++cnt[1];
    else ++cnt[0];
}

int main() {
    int T; scanf( "%d", &T );
    for( int t=1; t<=T; ++t ) {
        printf( "Roll-call: %d\n", t );
        int n;
        scanf( "%d%*c", &n );
        memset( cnt, 0, sizeof(cnt) );
        for( int i=0; i<n; ++i ) {
            gets( str );
            deal();
        }
        printf( "Present: %d out of %d\n", cnt[0], n );
        printf( "Needs to study at home: %d out of %d\n", cnt[1], n );
        printf( "Needs remedial work after school: %d out of %d\n", cnt[2], n );
        printf( "Absent: %d out of %d\n", cnt[3], n );
    }
}
