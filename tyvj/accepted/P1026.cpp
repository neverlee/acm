#include<cstdio>
bool field[250][250];
int row, col, no;
int r1,c1,r2,c2;
int main() {
	scanf( "%d%d%d", &row, &col, &no );
	while( no-- ) {
		scanf( "%d%d%d%d", &r1, &c1, &r2, &c2 );
		for( int i=r1; i<=r2; ++i )
			for( int j=c1; j<=c2; ++j )
				field[i][j]=1;
	}
	no=0;
	for( int i=1; i<=row; ++i )
		for( int j=1; j<=col; ++j )
			if( field[i][j] ) ++no;
	printf( "%d", no );
}
