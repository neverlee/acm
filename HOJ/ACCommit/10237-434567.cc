#include <cstdio>
#include <cstring>

#define abs(x) ((x)<0?(-(x)):(x))
const int INF = 0x7FFFffff;
int amount, ay[110], fa[110], fb[110], t;

int main() {
    scanf( "%d", &amount );
    for( int i=0; i<amount; ++i ) {
        scanf( "%d", ay+i );
        fa[i] = abs(ay[i]-ay[0]);
    }
    if( amount==1 ) {
        putchar(\'0\');
        return 0;
    }
    for( int i=1; i<amount; ++i ) {
        for( int j=0; j<amount; ++j ) {
            fb[j] = INF;
            for( int k=0; k<amount; ++k ) {
                t = fa[k] + abs(ay[i]-ay[j]) + abs(ay[j]-ay[k]);
                fb[j] = fb[j]<t?fb[j]:t;
            }
        }
        memcpy( fa, fb, sizeof(int)*amount );
    }
    t = fa[0];
    for( int i=1; i<amount; ++i )
        t = t<fa[i]?t:fa[i];
    printf( "%d\n", t );
}
