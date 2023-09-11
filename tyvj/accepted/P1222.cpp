#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define XX(x) (x)*(x)
int amount;
struct Coord{
	int x, y, z;
	void set( int ax, int ay, int az ) {
		x=ax; y=ay; z=az;
	}
	static double getDistance( const Coord &ca, const Coord &cb ) {
		__int64 x, y, z;
		x = XX((__int64)ca.x-cb.x);
		y = XX((__int64)ca.y-cb.y);
		z = XX((__int64)ca.z-cb.z);
		return sqrt( (double)(x+y+z) );
	}
}neut[1001];

struct Node{
	int to;
	double length;
	void set( int t, double l ) {
		to = t;
		length = l;
	}
};
void init() {
	int i;
	for( i=1; 3 == scanf("%d%d%d", &neut[i].x, &neut[i].y, &neut[i].z); ++i );
	amount = i;
	neut[0].set(-1,-1,-1);
}

double prim() {
	int i, j;
	Node data[1001];
	for( i=1; i<amount; ++i ) {
		data[i].set( i, Coord::getDistance( neut[0], neut[i] ) );
	}
	for( i=1; i<amount; ++i ) {
		int pmin=i;
		double dl;
		for( j=i+1; j<amount; ++j )
			pmin = data[pmin].length<data[j].length?pmin:j;
		swap( data[i], data[pmin] );
		for( j=i+1; j<amount; ++j ) {
			dl = Coord::getDistance( neut[data[i].to], neut[data[j].to] );
			if( dl<data[j].length ) {
				data[j].set( data[j].to, dl );
			}
		}
	}
	double ret=0;
	for( i=1; i<amount; ++i )
		ret += data[i].length;
	return ret;
}

int main() {
	init();
	printf( "%.4lf", prim() );
	return 0;
}
