#include<cstdio>
int dis[20001], f[20001];
int time, tire;
void imax( int &a, int b ) { a=a>b?a:b; };
int main() {
	scanf( "%d%d", &time, &tire );
	for( int i=1; i<=time; ++i ) {
		scanf( "%d", dis+i );
		dis[i]+=dis[i-1];
	}
	for( int i=2; i<=time; ++i ) {
		for( int k=1; 2*k<=i&&k<=tire; ++k )
			imax( f[i], f[i-k-k]+dis[i-k]-dis[i-k-k] );
		imax( f[i], f[i-1] );
	}
	printf( "%d", f[time] );
}
