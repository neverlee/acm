#include<cstdio>
#include<cstring>
int pt[256], sure[256], f[256];
char str[260];
void imax( int &a, int b ) { a=a>b?a:b; }
int main() {
	scanf( "%s", str );
	for( int i=0; str[i]; ++i )
		pt[ str[i] ] = 255-i;
	while( EOF != scanf( "%s", str ) ) {
		int len = strlen( str );
		for( int i=0; i<=len; ++i )
			sure[i] = pt[ str[i] ];
		f[0]=1;
		int last=1;
		for( int i=1; i<len; ++i ) {
			f[i]=1;
			for( int j=0; j<i; ++j )
			if( sure[i]<=sure[j] )
				imax( f[i], f[j]+1 );
			imax( last, f[i] );
		}
		printf( "%d", last );
	}
	putchar('\n');
}

