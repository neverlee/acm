#include <cstdio>
const int N=2000001;
int ay[N];
int main() {
    for( int i=1; i<N; ++i ) {
        if( !ay[i] || ay[i]>ay[i-1]+1 )
            ay[i] = ay[i-1]+1;
        for( int j=2, t=i+i; j<=i&&t<N; ++j, t+=i ) {
            if( !ay[t] || ay[t]>ay[i]+ay[j] )
                ay[t] = ay[i]+ay[j];
        }
    }
    int n;
    while( ~scanf( "%d", &n ) )
        printf( "%d\n", ay[n] );
}