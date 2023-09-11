#include <cstdio>
#include <algorithm>
using namespace std;
struct Box{
	int high, count, limit;
	friend bool operator<( const Box &ba, const Box &bb ) {
		return ba.limit<bb.limit;
	}
};
Box boxes[400];
int box_amount;
bool f[40001];
int main() {
	int i, j, k;
	scanf( "%d", &box_amount );
	for( i=0; i<box_amount; ++i )
		scanf( "%d%d%d", &boxes[i].high, &boxes[i].limit, &boxes[i].count );
	sort( boxes, boxes+box_amount );
	f[0]=1;
	for( i=0; i<box_amount; ++i ) {
		for( j=0; j<boxes[i].count; ++j ) {
			for( k=boxes[i].limit; k>=boxes[i].high; --k ) {
				if( f[ k-boxes[i].high] ) f[k]=1;
			}
		}
	}
	for( i=40000; i>=0&&f[i]==0; --i );
	printf( "%d", i );
	return 0;
}