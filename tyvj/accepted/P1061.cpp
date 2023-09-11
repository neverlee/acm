#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int nlen, nquery;
int want[200][200];

void init() {
	scanf( "%d%d", &nlen, &nquery );
	int i, j;
	for( i=0; i<nlen; ++i )
		for( j=0; j<nlen; ++j )
			scanf( "%d", want[i]+j );
}
struct Block{
	int xy[200][200];
	int z;
}bf[2], *fs, *fe;

void clear( Block *pb, int n ) {
	int i, j;
	for( i=0; i<nlen; ++i )
		for( j=0; j<nlen; ++j )
			pb->xy[i][j]=n;
}
void imin( int &a, int b ) { a=a<b?a:b; }
void dp() {
	const int MAXX = 0x0fffffff;
	fs = bf;
	fe = bf+1;
	clear( fs, MAXX );
	fs->xy[1][2]=0;
	fs->z=0;
	int i, j, q;
	for( q=0; q<nquery; ++q ) {
		int qry;
		scanf( "%d", &qry );
		fe->z = qry-1;
		clear( fe, MAXX );
		for( i=0; i<nlen; ++i )
			for( j=i+1; j<nlen; ++j )
			if( fs->xy[i][j] != MAXX ) {
				if( fe->z!=i && fe->z!=j )
					imin( fe->xy[i][j], fs->xy[i][j]+want[fs->z][fe->z] );
				int x, y;
				if( fe->z!=i && fe->z!=fs->z ) {
					x = i; y = fs->z;
					if( x>y ) swap( x, y );
					imin( fe->xy[x][y], fs->xy[i][j]+want[j][fe->z] );
				}
				if( fe->z!=j && fe->z!=fs->z ) {
					x = j; y = fs->z;
					if( x>y ) swap( x, y );
					imin( fe->xy[x][y], fs->xy[i][j]+want[i][fe->z] );
				}
			}
		swap( fs, fe );
	}
	int nmin=0x7fffffff;
	for( i=0; i<nlen; ++i )
		for( j=0; j<nlen; ++j )
			imin( nmin, fs->xy[i][j] );
	printf( "%d", nmin );
}

int main() {
	init();
	dp();
	return 0;
}







