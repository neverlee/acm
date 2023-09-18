#include <cstdio>
#include <cstring>
const int SIZE = 1000010;
char str[SIZE];
int next[SIZE], len, nxtv[SIZE];
void get_next() {
    int i, j;
    next[1] = 0;
    for( i=2, j=1; i<=len; ) {
        if( j==0 || str[i]==str[j] ) {
            if( j==0 && str[i]==str[j] ) ++j;
            next[i] = j;
            ++j; ++i;
        }else j = next[j];
    }
    /*for( i=1; i<=len; ++i )
        printf( "%4c", str[i] );
    puts("");
    for( i=1; i<=len+1; ++i )
        printf( "%4d", next[i] );
    puts("");*/
}

int answer() {
    int ln, dn;
    ln = len-next[len];
    if( len%ln!=0 ) dn=1;
    else dn = len/ln;
    int ti, tj;
    for( ti=len, tj=ti-ln; tj>0; --ti, --tj ) {
        if( str[ti] != str[tj] )
            return 1;
    }
    return dn;
}

int main() {
    while( gets( str+1 ), strcmp( str+1, "." ) ) {
        len = strlen( str+1 );
        get_next();
        printf( "%d\n", answer() );
    }
}
