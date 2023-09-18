//10318-山头狙击战.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 100010;

int amount, ay[SIZE], dst;

bool check( int dk ) {
	int fb;
	fb = 0;
	for( int i=0; i<amount; ++i ) {
		if( fb>ay[i] ) return 0;
		if( fb+dst>=ay[i] ) 
			fb = fb+dk;
		else fb = ay[i]-dst+dk;
	}
	return 1;
}

int main() {
	scanf( "%d%d", &amount, &dst );
	for( int i=0; i<amount; ++i )
		scanf( "%d", ay+i );
	sort( ay, ay+amount );
	int low, high, mid;
	low = 0; high = ay[amount-1]/amount + 1;
	while( low<high ) {
		mid = (low+high)/2;
		if( check(mid) ) low = mid+1;
		else high = mid;
	}
	printf( "%d", low-1 );
}
