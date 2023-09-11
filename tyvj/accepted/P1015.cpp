#include<cstdio>
int main() {
	int pr[11], f[110];
	for( int i=1; i<11; ++i ) scanf( "%d", pr+i );
	scanf( "%d", pr );
	for( int i=1; i<=pr[0]; ++i ) f[i]=1E8;
	f[0]=0;
	for( int i=1; i<11; ++i )
		for( int j=0; j+i<=pr[0]; ++j ) {
			int k=f[j]+pr[i];
			f[j+i]=f[j+i]<k?f[j+i]:k;
		}
	printf( "%d", f[pr[0]] );
}
