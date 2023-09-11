#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define ROW(X) ( 0xfff & (X) )
#define COL(X) ( 0xfff & ((X)>>12) )
#define DRC(X) ( 0xf   & ((X)>>24) )
#define MAKE( L, H, D ) ( (L) | ((H)<<12) | ((D)<<24) )

const int SIZE = 1010;
const int INF = 0x0fFfFfFf;

char info[SIZE][SIZE];
int f[SIZE][SIZE][4];
int g[SIZE][SIZE][4];
char ud[SIZE][SIZE];
int row, col, mod;
int start, end;
int dx[] = { -1, 0, 1, 0 };
int dy[] = {  0, 1, 0,-1 };

int &rf( int n ) { return f[ ROW(n) ][ COL(n) ][ DRC(n) ]; }
int &rg( int n ) { return g[ ROW(n) ][ COL(n) ][ DRC(n) ]; }

void init() {
	for( int i=1; i<=row; ++i )
		scanf( "%s", info[i]+1 );
	for( int i=0; i<=row+1; ++i )
		info[i][0] = info[i][col+1] = 0;
	for( int i=0; i<=col+1; ++i )
		info[0][i] = info[row+1][i] = 0;
	int r1, c1, r2, c2; char d;
	scanf( "%d%d%d%d %c", &r1, &c1, &r2, &c2, &d );
	++r1; ++c1; ++r2; ++c2;
	if( d=='N' ) d=0;
	else if( d=='E' ) d=1;
	else if( d=='S' ) d=2;
	else if( d=='W' ) d=3;
	start = MAKE( r1, c1, d );
	end = MAKE( r2, c2, 0 );
}

void gobfs() {
	for( int i=0; i<=row+1; ++i )
		for( int j=0; j<=col+1; ++j )
			for( int k=0; k<4; ++k )
				f[i][j][k] = INF;
	queue<int> qi;
	qi.push( start );
	rf(start) = 0;
	while( !qi.empty() ) {
		int pr, pc, pd, nr, nc, nd;
		pr = ROW( qi.front() );
		pc = COL( qi.front() );
		pd = DRC( qi.front() );
		nr = pr+dx[pd];
		nc = pc+dy[pd];
		if( f[nr][nc][pd]>f[pr][pc][pd]+1 && info[nr][nc]=='.' ) {
			f[nr][nc][pd] = f[pr][pc][pd]+1;
			qi.push( MAKE( nr, nc, pd ) );
		}
		for( int i=1; i<=3; ++i )
		if( i!=2 ) {
			nd = (pd+i)%4;
			if( f[pr][pc][nd]>f[pr][pc][pd]+1 ) {
				f[pr][pc][nd] = f[pr][pc][pd]+1;
				qi.push( MAKE( pr, pc, nd ) );
			}
		}
		qi.pop();
	}
}

void shortbfs() {
	int min=INF;
	int er=ROW(end), ec=COL(end);
	for( int i=0; i<4; ++i )
		if( min > f[er][ec][i] )
			min = f[er][ec][i];
	if( min == INF ) return;
	queue<int> qi;
	memset( g, 0, sizeof(g) );
	memset( ud, 0, sizeof(ud) );
	for( int i=0; i<4; ++i )
		if( f[er][ec][i] == min ) {
			g[er][ec][i] = 1;
			qi.push( MAKE( er, ec, i ) );
			ud[er][ec] |= 1<<i;
		}
	while( !qi.empty() ) {
		int pr, pc, pd, nr, nc, nd;
		pr = ROW( qi.front() );
		pc = COL( qi.front() );
		pd = DRC( qi.front() );
		nr = pr-dx[pd];
		nc = pc-dy[pd];
		if( f[nr][nc][pd]==f[pr][pc][pd]-1 ) {
			g[nr][nc][pd] += g[pr][pc][pd];
			g[nr][nc][pd] %= mod;
			if( (ud[nr][nc]&(1<<pd))==0 ) {
				qi.push( MAKE( nr, nc, pd ) );
				ud[nr][nc] |= (1<<pd);
			}
		}
		for( int i=1; i<=3; ++i )
		if( i!=2 ) {
			nd = (pd+i)%4;
			if( f[pr][pc][nd]==f[pr][pc][pd]-1 ) {
				g[pr][pc][nd] += g[pr][pc][pd];
				g[pr][pc][nd] %= mod;
				if( (ud[pr][pc]&(1<<nd))==0 ) {
					qi.push( MAKE( pr, pc, nd ) );
					ud[pr][pc] |= (1<<nd);
				}
			}
		}
		qi.pop();
	}
}

int main() {
	for( int T=1; scanf( "%d%d%d", &row, &col, &mod ), row; ++T ) {
		init();
		gobfs();
		shortbfs();
		printf( "Case %d: %d %d\n", T, mod, rg(start)?rg(start):-1 );
	}
}

