//10425-博弈(chess).cpp
#include <cstdio>
#include <cstring>
int f[16][16];
int main() {
	int w, b, k;
	memset( f, -1, sizeof(f) );
	f[0][0]=0;
	while( EOF != scanf( "%d%d", &w, &b ) ) {
		for( int i=15; i>=0; --i )
			for( int j=15; j>=0; --j ) {
				if( i>0 && f[i-1][j]!=-1 ) {
					k = f[i-1][j]+w;
					f[i][j] = k>f[i][j]?k:f[i][j];
				}
				if( j>0 && f[i][j-1]!=-1 ) {
					k = f[i][j-1]+b;
					f[i][j] = k>f[i][j]?k:f[i][j];
				}
			}
	}
	printf( "%d", f[15][15] );
}
