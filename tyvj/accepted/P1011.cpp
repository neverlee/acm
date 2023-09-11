#include<cstdio>

int row, col, map[110][60]={0};
void Init() {
	scanf( "%d%d", &row, &col );
	for( int i=0; i<row; ++i )
		for( int j=1; j<=col; ++j )
			scanf( "%d", map[i+j]+j );
}
int f[110][60][60];
int dp[]={-1,-1, 0, 0};
int dq[]={-1, 0,-1, 0};
int imax( int a, int b ) { return a>b?a:b; }
void Dp() {
	f[2][1][2]=map[2][1]+map[2][2];
	for( int i=3; i<row+col; ++i ) {
		for( int p=1; p<col; ++p ) {
			for( int q=p+1; q<=col; ++q ) {
				int tm=0;
				for( int k=0; k<4; ++k ) {
					tm = imax( tm, f[i-1][p+dp[k]][q+dq[k]] );
				}
				f[i][p][q] = tm + map[i][p]+map[i][q];
				//printf( "%4d", f[i][p][q] );
			}
		}
		//printf( "\n" );
	}
	printf( "%d", f[row+col-1][col-1][col] );
}
int main() {
	Init();
	Dp();
}

