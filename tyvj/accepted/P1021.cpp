#include<cstdio>
#include<algorithm>
#define int64 long long
using namespace std;
int n, ay[10000];
int main() {
	scanf( "%d", &n );
	for( int i=0; i<n; ++i )
		scanf( "%d", ay+i );
	sort( ay, ay+n );
	int64 sum=0;
	for( int i=1; i<=n; ++i ) {
		sum+=( (ay[i]-ay[i-1]) * (int64)( (n-i)*i ) );
	}
	printf( "%ld", sum*2 );
}
