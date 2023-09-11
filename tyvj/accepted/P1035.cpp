#include <cstdio>
#include <cstring>

int map[6000][4], mlen;
void init() {
	int rect[110][110]={0}, size, empty;
	int i, j, k, d;
	scanf( "%d%d", &size, &empty );
	for( i=0; i<=size+1; ++i ) rect[0][i]=rect[size+1][i]=-1;
	for( i=1; i<=size; ++i ) rect[i][0]=rect[i][size+1]=-1;
	int r, c;
	while( empty-- ) {
		scanf( "%d%d", &r, &c );
		rect[r][c]=-1;
	}
	for( i=1, d=1, k=0; i<=size; ++i, d=3-d ) {
		for( j=d; j<=size; j+=2 )
			if( rect[i][j]==0 )
				rect[i][j] = k++;
	}
	int dr[]={-1, 0, 0, 1};
	int dc[]={ 0,-1, 1, 0};
	for( i=1, d=2, mlen=0; i<=size; ++i, d=3-d ) {
		for( j=d; j<=size; j+=2, ++k )
		if( rect[i][j]!=-1 ) {
			for( k=0; k<4; ++k )
				map[mlen][k]=rect[i+dr[k]][j+dc[k]];
			++mlen;
		}
	}
}
int lby[6000];
bool yuse[6000];
bool getHalf( int to ) {
	int i, k;
	for( i=0; i<4; ++i ) {
		k = map[to][i];
		if( k>=0 && yuse[k]==0 ) {
			yuse[k]=1;
			if( lby[k]==-1 || getHalf( lby[k] ) ) {
				lby[k] = to;
				return 1;
			}
		}
	}
	return 0;
}
void getMax() {
	memset(lby, -1, sizeof(lby));
	int i, num;
	num = 0;
	for( i=0; i<mlen; ++i ) {
		memset(yuse, 0, sizeof(yuse));
		if( getHalf( i ) )
			++num;
	}
	printf( "%d", num );
}
int main() {
	init();
	getMax();
	return 0;
}