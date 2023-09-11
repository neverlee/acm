#include<cstdio>
int num, card[100];
int f[100][100];
int main() {
	scanf( "%d", &num );
	for( int i=0; i<num; ++i ) scanf( "%d", card+i );
	for( int i=0; i<num; ++i )
		for( int j=i+2; j<num; ++j ) f[i][j]=2E9;
	for( int i=0; i+1<num; ++i ) f[i][i+1]=0;
	for( int l=2; l<num; ++l ) {
		for( int i=0; i+l<num; ++i ) {
			for( int k=i+1; k<i+l; ++k ) {
				int it=f[i][k]+f[k][i+l]+card[i]*card[k]*card[i+l];
				f[i][i+l]=it<f[i][i+l]?it:f[i][i+l];
			}
		}
	}
	printf( "%d", f[0][num-1] );
}
