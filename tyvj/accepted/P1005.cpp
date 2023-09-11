#include<cstdio>
#include<cstring>
int aw, n;
int f[1010];
int main() {
	scanf( "%d %d", &aw, &n );
	memset( f, -1, sizeof(f) ); f[0]=0;
	int w,v;
	while( n-- ) {
		scanf( "%d %d", &w, &v );
		for( int i=aw; i>=w; --i )
			if( f[i-w]!=-1 && f[i-w]+v>f[i] )
				f[i] = f[i-w]+v;
	}
	for( int i=aw; i>0; --i )
		f[0]=f[0]>f[i]?f[0]:f[i];
	printf( "%d", f[0] );
}
