//10727-Building rooms.cpp
#include <cstdio>
#include <cstring>

const int SIZE=100;

int lky[SIZE];
bool used[SIZE];
bool bmap[SIZE][SIZE];
int xlen, ylen;
bool can( int t ) {
	for( int i=0; i<ylen; ++i ) {
		if( !used[i] && bmap[t][i] ) {
			used[i] = 1;
			if( lky[i]==-1 || can( lky[i] ) ) {
				lky[i] = t;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int road, num, x, y;
	num = 0;
	scanf( "%d%d%d", &xlen, &ylen, &road );
	while( road-- ) {
		scanf( "%d%d", &x, &y );
		bmap[x][y] = 1;
	}
	memset( lky, -1, sizeof(lky) );
	for( int i=0; i<xlen; ++i ) {
		memset( used, 0, sizeof(used) );
		if( can(i) )
			++num;
	}
	printf( "%d", num );
}
