#include <cstdio>
#include <cstring>

int paste, amount, f[25600];

int main() {
	scanf( "%d%d", &paste, &amount );
	memset( f, -1, sizeof(f) );
	f[0]=0;
	int all = paste*255;
	while( amount-- ) {
		int kt, ie;
		scanf( "%d", &kt );
		ie = all-kt;
		for( int i=0; i<=ie; ++i ) {
			if( f[i+kt]==-1 || f[i+kt]>f[i] )
				f[i+kt] = f[i]+1;
		}
	}
	int ed;
	for( ed=1; f[ed]<=paste && f[ed]!=-1; ++ed );
	printf( "%d", ed-1 );
}
