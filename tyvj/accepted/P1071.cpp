#include <cstdio>
int a[3000], b[3000], f[3000], n;
int main() {
	int i, j, last;
	scanf( "%d", &n );
	for( i=0; i<n; ++i ) scanf( "%d", a+i );
	for( i=0; i<n; ++i ) scanf( "%d", b+i );
	for( i=0; i<n; ++i ) {
		last = 0;
		for( j=0; j<=i; ++j ) {
			if( a[i]>b[j] && f[j]>last ) last=f[j];
			else if( a[i]==b[j] && f[j]<last+1 ) f[j]=last+1;
		}
	}
	last=0;
	for( i=0; i<n; ++i ) last = last>f[i]?last:f[i];
	printf( "%d", last );
	return 0;
}