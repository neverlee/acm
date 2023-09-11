#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
int h, w; __int64 l;
int nx[]={-1, 0, 1, 0};
int ny[]={ 0, 1, 0,-1};
char map[110][110];
int sx, sy, drt;
bool init() {
	int i, j;
	scanf( "%d%d%I64d", &h, &w, &l );
	if( h==0 && w==0 && l==0 ) return 0;
	for( i=1; i<=h; ++i )
		scanf( "%s", map[i]+1 );
	for( i=1; i<=w; ++i )
		map[h+1][i]=0;
	for( i=1; i<=h; ++i )
		for( j=1; j<=w; ++j )
			if( isalpha( map[i][j] ) ) {
				sx = i; sy = j;
				switch( map[i][j] ) {
					case 'N': drt = 0; break;
					case 'E': drt = 1; break;
					case 'S': drt = 2; break;
					case 'W': drt = 3; break;
				}
				map[i][j]='.';
				break;
			}
	return 1;
}

int foot[4][110][110];
void output( int x, int y, int i ) {
	printf( "%d %d ", x, y );
	if( i==0 ) putchar('N');
	if( i==1 ) putchar('E');
	if( i==2 ) putchar('S');
	if( i==3 ) putchar('W');
	putchar('\n');
}

void work() {
	int k=0;
	for( int i=0; i<4; ++i )
		if( map[sx+nx[i]][sy+ny[i]]!='.' ) ++k;
	if( k==4 || l==0 ) {
		output( sx, sy, drt );
		return;
	}
	memset( foot, -1, sizeof( foot ) );
	foot[drt][sx][sy] = 0;
	int kx=sx, ky=sy, lv=0;
	while( 1 ) {
		int dx, dy;
		dx = kx+nx[drt];
		dy = ky+ny[drt];
		if( map[dx][dy]=='.' ) {
			++lv;
			kx = dx; ky = dy;
			if( lv==l ) {
				output( kx, ky, drt );
				return;
			}
			if( foot[drt][dx][dy]==-1 ) {
				foot[drt][dx][dy]=lv;
			}else break;
		}else drt = (drt+1)%4;
	}
	l -= foot[drt][kx][ky];
	l %= (lv-foot[drt][kx][ky]);
	while( l>0 ) {
		int dx, dy;
		dx = kx+nx[drt];
		dy = ky+ny[drt];
		if( map[dx][dy]=='.' ) {
			kx = dx; ky = dy;
			--l;
		}else drt = (drt+1)%4;
	}
	output( kx, ky, drt );
	return;
}

int main() {
	while( init() )
		work();
}






