#include<cstdio>
int f[32][32];
int main() {
	int n,m;
	scanf( "%d %d", &n, &m );
	f[0][1]=1;
	for( int i=0; i<m; ++i ) {
		f[i][0]=f[i][n]; f[i][n+1]=f[i][1];
		for( int j=1; j<=n; ++j )
			f[i+1][j]=f[i][j-1]+f[i][j+1];
	}
	printf( "%d", f[m][1] );
}
