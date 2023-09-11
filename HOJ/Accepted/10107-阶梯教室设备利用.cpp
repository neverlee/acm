//10107-阶梯教室设备利用.cpp
#include <cstdio>
#include <algorithm>
using namespace std;
struct Interval{
	int st, ed;
	friend bool operator<( const Interval &ia, const Interval &ib ) {
		return ia.ed<ib.ed;
	}
	void set( int s, int e ) {
		st=s; ed=e;
	}
} inv[10001];
int amount;
void init() {
	int i;
	scanf( "%d", &amount );
	inv[0].set( 0, 0 );
	for( i=1; i<=amount; ++i )
		scanf( "%d%d", &inv[i].st, &inv[i].ed );
	sort( inv+1, inv+amount+1 );
}

int f[10001];
int max( int a, int b ) { return a>b?a:b; }
void dp() {
	int i, imax;
	f[0]=0;
	imax=0;
	for( i=1; i<=amount; ++i ) {
		int low, high, mid;
		int key = inv[i].st;
		low = 0; high = i;
		while( low<high ) {
			mid = (low+high)/2;
			if( inv[mid].ed>key ) high=mid;
			else low = mid+1;
		}
		mid = high;
		f[i] = max( f[i-1], f[mid-1]+inv[i].ed-inv[i].st );
		imax = max( f[i], imax );
	}
	printf( "%d", imax );
}

int main() {
	init();
	dp();
	return 0;
}