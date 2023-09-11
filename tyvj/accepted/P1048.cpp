#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int SIZE = 2010;
int ht[SIZE], hk[SIZE], amount;
void init() {
	scanf( "%d", &amount );
	int i;
	for( i=1; i<=amount; ++i ) scanf( "%d", ht+i );
	for( i=1; i<=amount; ++i ) scanf( "%d", hk+i );
	sort( ht+1, ht+1+amount, greater<int>() );
	sort( hk+1, hk+1+amount, greater<int>() );
}
int f[SIZE][SIZE];
int cmp( int tj, int king ) {
	tj = ht[tj] - hk[king];
	if( tj>0 ) return 1;
	if( tj==0 ) return 0;
	return -1;
}
void imax( int &a, int b ) {
	a = a>b?a:b;
}
void dp() {
	int i, j;
	for( i=1; i<=amount; ++i )
		for( j=0; j<=amount; ++j ) f[i][j] = -SIZE;
	for( i=1; i<=amount; ++i ) {
		for( j=0; j<=i; ++j ) {
			if( i-1>=j )
			imax( f[i][j], f[i-1][j] + cmp( amount-i+1+j, i ) );
			if( j-1>=0 )
			imax( f[i][j], f[i-1][j-1] + cmp( j, i ) );
		}
	}
	j = -SIZE;
	for( i=0; i<=amount; ++i ) {
		imax( j, f[amount][i] );
	}
	printf( "%d\n", j*200 );
}
int main() {
	init();
	dp();
	return 0;
}