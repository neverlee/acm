#include <cstdio>
int n, ay[10000];
bool o[10000];

int main() {
    scanf( "%d%d", &n, ay+0 );
    char str[10];
    for( int i=1; i<=n; ++i ) {
        scanf( "%s%d", str, ay+i );
        o[i] = str[4];
    }
    for( int i=n; i>0; --i ) {
        if( o[i] ) ay[i-1] -= ay[i];
        else ay[i-1] += ay[i];
    }
    printf( "%d", ay[0] );
}