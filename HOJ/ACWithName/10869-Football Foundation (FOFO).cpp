//10869-Football Foundation (FOFO).cpp
#include<cstdio>
int r, c, s;
int dr[]={0,-1, 1, 0, 0};
int dc[]={0, 0, 0,-1, 1};
int rect[1050][1050];

int main() {
	while( scanf( "%ld %ld %ld%*c", &r, &c ,&s ), r ) {
		for( int i=0; i<=c+1; ++i ) rect[r+1][i]=0;
		for( int i=1; i<=r; ++i ) {
			for( int j=1; j<=c; ++j ) {
				rect[i][j]=getchar();
				switch( rect[i][j] ) {
				case 'N': rect[i][j]=1; break;
				case 'S': rect[i][j]=2; break;
				case 'W': rect[i][j]=3; break;
				case 'E': rect[i][j]=4; break;
				}
			}
			rect[i][c+1]=0;
			getchar();
		}

		int pr=1, pc=s, d, len=0;
		while( 1 ) {
			d = rect[pr][pc];
			rect[pr][pc] = --len;
			pr += dr[d];
			pc += dc[d];
			if( rect[pr][pc] ==0 ) {
				printf( "%ld step(s) to exit\n", -len );
				break;
			}else if( rect[pr][pc]<0 ) {
				printf( "%ld step(s) before a loop of %ld step(s)\n"
						, -rect[pr][pc]-1, rect[pr][pc]-len+1 );
				break;
			}
		}
	}
}