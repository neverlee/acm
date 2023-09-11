#include <cstdio>
#include <cmath>
#include <cstring>

int x[20], y[20];
double d[20][20];
int amount;

void init() {
	scanf( "%d", &amount );
	for( int i=0; i<amount; ++i )
		scanf( "%d%d", x+i, y+i );
	for( int i=0; i<amount; ++i )
		for( int j=i+1; j<amount; ++j ) {
			int xl, yl;
			xl = x[i]-x[j]; yl = y[i]-y[j];
			d[i][j] = sqrt( (double) (xl*xl+yl*yl) );
		}
}

double imin=1E15;
bool used[20];

void dfs( double sum, int remain ) {
	if( 0 == remain || sum>=imin ) {
		if( sum<imin ) imin = sum;
		return;
	}
	int f;
	for( f=0; used[f]; ++f );
	used[f] = 1;
	for( int i=f+1; i<amount; ++i )
	if( !used[i] ) {
		used[i] = 1;
		dfs( sum+d[f][i], remain-2 );
		used[i] = 0;
	}
	used[f] = 0;
}

int main() {
	init();
	dfs( 0, amount );
	printf( "%.2lf", imin );
}
