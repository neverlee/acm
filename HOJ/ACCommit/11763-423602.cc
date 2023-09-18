#include <cstdio>
#include <cstring>

typedef __int64 lli;
char str[30];
int cnt[26], len;
lli bt[21] = {1};

lli fac( int il ) {
    lli ret;
    ret = bt[ il ];
    for( int i=0; i<26; ++i )
        if( cnt[i] )
            ret /= bt[ cnt[i] ];
    return ret;
}

void getitem() {
    len = strlen( str );
    memset( cnt, 0, sizeof(cnt) );
    for( int i=0; i<len; ++i ) {
        str[i] -= \'A\';
        ++cnt[ str[i] ];
    }
    lli ret=0;
    for( int i=0; i<len-1; ++i ) {
        for( int j=0; j<str[i]; ++j )
        if( cnt[j] ) {
            --cnt[j];
            ret += fac( len-i-1 );
            ++cnt[j];
        }
        --cnt[ str[i] ];
    }
    printf( "%I64d\n", ret );
}

int main() {
    int n;
    scanf( "%d", &n );
    for( int i=1; i<=20; ++i )
        bt[i] = bt[i-1]*i;
    while( n-- ) {
        scanf( "%s", str );
        getitem();
    }
}