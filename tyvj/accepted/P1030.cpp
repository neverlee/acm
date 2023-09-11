#include <cstdio>

int row, col, sr,sc;
char map[110][110];
void init() {
	scanf( "%d%d%d%d", &col, &row, &sc, &sr );
	int i;
	getchar();
	for( i=1; i<=row; ++i ) gets( map[i]+1 );
}
struct Pat{
	int r, c;
};
Pat queue[15000], *pLeft, *pRight;
int foot;
int dr[]={-1,1,1,-1,-1,0,0,1};
int dc[]={-1,1,-1,1,0,-1,1,0};
void pushRight( int r, int c ) {
	pRight->r = r;
	pRight->c = c;
	++pRight;
}
void initQueue() {
	pLeft = pRight = queue;
	pushRight( sr, sc );
	pushRight( 0, 0 );
}

void bfs() {
	foot = 0;
	while( pLeft<pRight ) {
		if( pLeft->r == 0 ) {
			if( pRight-pLeft!=1 ) {
				pushRight( 0, 0 );
				++foot;
			}
		}else {
			int i, ar, ac;
			for( i=0; i<8; ++i ) {
				ar = pLeft->r + dr[i];
				ac = pLeft->c + dc[i];
				if( map[ar][ac]=='.' ) {
					map[ar][ac]='#';
					pushRight( ar, ac );
				}
			}
		}
		++pLeft;
	}
	printf( "%d", foot );
}
int main() {
	init();
	initQueue();
	bfs();
	return 0;
}