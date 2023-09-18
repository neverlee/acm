//12355-Stock Prices.cpp
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int SIZE = 1000010;
struct Price{
	int day;
	int price;
	bool friend operator<( const Price &pa, const Price &pb ) {
		return pa.price<pb.price || (pa.price==pb.price&&pa.day<pb.day);
	}
} date[SIZE];
int ay[SIZE];
int n, low, high;
int main() {
	for( int T=1; scanf( "%d%d%d", &n, &low, &high ), n; ++T ) {
		printf( "Case %d\n", T );
		for( int i=0; i<n; ++i ) {
			scanf( "%d", &date[i].price );
			date[i].day = i+1;
		}
		sort( date, date+n );
		for( int i=0; i<low; ++i )
			ay[i] = date[i].day;
		sort( ay, ay+low );
		printf( "%d", ay[0] );
		for( int i=1; i<low; ++i ) 
			printf( " %d", ay[i] );
		putchar('\n');
		for( int i=0; i<high; ++i )
			ay[i] = date[i+n-high].day;
		sort( ay, ay+high, greater<int>() );
		printf( "%d", ay[0] );
		for( int i=1; i<high; ++i ) 
			printf( " %d", ay[i] );
		putchar('\n');
	}
}

