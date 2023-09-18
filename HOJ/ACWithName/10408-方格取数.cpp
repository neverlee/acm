//10408-方格取数.cpp
#include<cstdio>
 
int row, map[110][60];
void Init() {
    scanf( "%d", &row );
	int x, y, n;
	while( scanf( "%d%d%d", &x, &y, &n ), x||y||n )
		map[x+y-1][x]=n;
}
int f[110][60][60];
int dp[]={-1,-1, 0, 0};
int dq[]={-1, 0,-1, 0};
int imax( int a, int b ) { return a>b?a:b; }
void Dp() {
	int drr;
	drr=row*2;
    f[2][1][2]=map[2][1]+map[2][2]+map[1][1];
    for( int i=3; i<drr; ++i ) {
        for( int p=1; p<row; ++p ) {
            for( int q=p+1; q<=row; ++q ) {
                int tm=0;
                for( int k=0; k<4; ++k ) {
                    tm = imax( tm, f[i-1][p+dp[k]][q+dq[k]] );
                }
                f[i][p][q] = tm + map[i][p]+map[i][q];
            }
        }
    }
    printf( "%d", f[drr-1][row-1][row] );
}
int main() {
    Init();
    Dp();
}
