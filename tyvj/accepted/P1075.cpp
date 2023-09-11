#include <cstdio>
int amount, coin[2001];

void init() {
	int i;
	scanf( "%d", &amount );
	for( i=amount; i>0; i-- )
		scanf( "%d", coin+i );
	for( i=1; i<=amount; ++i )
		coin[i]+=coin[i-1];
}
int f[2001][2001];
void imax( int &a, int b ) { a=a>b?a:b; }
void dp() {
	int i, j;
	for( i=1; i<=amount; ++i )
		for( j=1; j<=i; ++j ) {
			int k;
			k = 2*j<i-j?2*j:i-j;
			f[i][j] = coin[i]-(i>=j?f[i-j][k]:0);
			imax( f[i][j], f[i][j-1] );
		}
	printf( "%d", f[amount][2] );
}
int main() {
	init();
	dp();
	return 0;
}








