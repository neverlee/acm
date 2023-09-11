//12089-Counterattack.cpp
#include<cstdio>
int t, n, s1, s2;
short inf[4][100010];
int dp[2][2];
int i,j,p,r;
int IMin( int a, int b ){ return a<b?a:b; }
int k; char c;
int main() {
	scanf( "%ld", &t );
	while( t-- ) {
		scanf( "%ld%ld%ld", &n, &dp[0][0], &dp[1][0] );
		scanf( "%ld%ld", &s1, &s2 );
		for( i=0; i<4; ++i )
			for( j=1; j<n; ++j ) {
				while( (c=getchar())<'0' );
				inf[i][j]=c-'0';
				while( (c=getchar())>='0' )inf[i][j]=inf[i][j]*10+c-'0';
			}
		p=0;
		for( int i=1; i<n; ++i ) {
			r=1-p;
			dp[0][r] = IMin( dp[0][p]+inf[1][i] , dp[1][p]+inf[2][i] );
			dp[1][r] = IMin( dp[1][p]+inf[3][i] , dp[0][p]+inf[0][i] );
			p=r;
		}
		printf( "%ld\n", IMin( dp[0][p]+s1, dp[1][p]+s2 ) );
	}
}
