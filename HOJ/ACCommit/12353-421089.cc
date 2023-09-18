#include <cstdio>

int n, ay[22];
bool is_same() {
    for( int i=1; i<n; ++i )
        if( ay[i]!=ay[i-1] )
            return 0;
    return 1;
}
int iabs( int a, int b ) {
    int c=a-b;
    return c>=0?c:-c;
}
void opt() {
    ay[n] = ay[0];
    for( int i=0; i<n; ++i )
        ay[i] = iabs( ay[i], ay[i+1] );
}
        
int main() {
    for( int T=1; scanf( "%d", &n ), n; ++T ) {
        for( int i=0; i<n; ++i )
            scanf( "%d", ay+i );
        if( is_same() ) {
            printf( "Case %d: 0 iterations\n", T );
            continue;
        }
        bool flag=1;
        for( int i=1; i<=1000; ++i ) {
            opt();
            if( is_same() ) {
                printf( "Case %d: %d iterations\n", T, i );
                flag=0;
                break;
            }
        }
        if( flag ) printf( "Case %d: not attained\n", T );
    }
}