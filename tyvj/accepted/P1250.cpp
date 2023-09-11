#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int cross, cycle;
int maps[110][110];
const int MMAX = 0x7fffffff;
void input() {
	int x, y, i, road, bit;
	scanf( "%d%d", &cross, &road );
	memset( maps, 0, sizeof(maps) );
	bit = MMAX;
	while( road-- ) {
		scanf( "%d%d", &x, &y );
		maps[x][y] = maps[y][x] = bit;
	}
	scanf( "%d", &cycle );
	for( i=0, bit=1; i<cycle; ) {
		scanf( "%d%d", &x, &y );
		if( x==0&&y==0 ){
			bit<<=1;
			++i;
			continue;
		}
		int nb;
		nb = ~bit;
		maps[x][y] &= nb;
		maps[y][x] &= nb;
	}
	if( cycle==0 ) cycle=1;
	bit = (1<<cycle)-1;
	for( i=1; i<=cross; ++i )
		for( int j=1; j<=cross; ++j )
			maps[i][j] &= bit;
}

int fn[110];
struct Cmp{
	bool operator() ( const int &a, const int &b ) {
		return fn[a]>fn[b];
	}
};
void dijkstra() {
	int bit;
	priority_queue< int, vector<int>, Cmp > dsq;
	for( int i=0; i<=cross; ++i ) fn[i] = MMAX;
	fn[1] = 0;
	dsq.push( 1 );
	bit = (1<<cycle)-1;
	while( !dsq.empty() ) {
		int pi, i, j, scb;
		pi = dsq.top();
		while( !dsq.empty() && dsq.top()==pi ) dsq.pop();
		for( i=1; i<=cross; ++i )
		if( maps[pi][i]!=MMAX ) {
			scb = (1<<(fn[pi]%cycle));
			for( j=1; j<=cycle; ++j ) {
				if( (scb&maps[pi][i]) > 0 ) {
					if( fn[pi]+j<fn[i] ) {
						fn[i] = fn[pi]+j;
						dsq.push( i );
					}
					break;
				}
				scb <<= 1;
				if( scb>bit ) scb=1;
			}
		}
	}
}

int main() {
	input();
	dijkstra();
	if( fn[cross]==MMAX ) puts("No solution.");
	else printf( "%d", fn[cross] );
}