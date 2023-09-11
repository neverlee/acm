#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int n, ay[10000], by[10000];
int main() {
	scanf( "%d", &n );
	for( int i=0; i<n; ++i ) scanf( "%d", ay+i );
	for( int i=0; i<n; ++i ) scanf( "%d", by+i );
	sort( ay, ay+n );
	sort( by, by+n, greater<int>() );
	int r=0;
	for( int i=0; i<n; ++i ) r+=abs(ay[i]-by[i]);
	printf( "%d", r );
}
