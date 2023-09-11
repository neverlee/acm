//10089-Cornfields.cpp
#include <cstdio>
const int SIZE = 260;
int imax[SIZE][SIZE], imin[SIZE][SIZE];
int osz, isz, query;
void init() {
	scanf( "%d%d%d", &osz, &isz, &query );
	for( int i=1; i<=osz; ++i )
		for( int j=1; j<=osz; ++j ) {
			scanf( "%d", imax[i]+j );
			imin[i][j]=imax[i][j];
		}
}
void gmax( int &a, int b ) { a=a>b?a:b; }
void gmin( int &a, int b ) { a=a<b?a:b; }
void calu() {
	for( int i=1; i<=osz; ++i )
		for( int j=isz; j<=osz; ++j ) {
			int p=j-isz+1;
			for( int k=j-isz+2; k<=j; ++k ) {
				gmax( imax[i][p], imax[i][k] );
				gmin( imin[i][p], imax[i][k] );
			}
		}
	int nsz;
	nsz = osz-isz+1;
	for( int i=1; i<=nsz; ++i )
		for( int j=1; j<=nsz; ++j )
			for( int k=i+1, ke=i+isz; k<ke; ++k ) {
				gmax( imax[i][j], imax[k][j] );
				gmin( imin[i][j], imin[k][j] );
			}
	for( int i=1; i<=nsz; ++i )
		for( int j=1; j<=nsz; ++j )
			imax[i][j]-=imin[i][j];
}
void answer() {
	int x, y;
	while( query-- ) {
		scanf( "%d%d", &x, &y );
		printf( "%d\n", imax[x][y] );
	}
}
int main() {
	init();
	calu();
	answer();
}