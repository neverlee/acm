//10066-Maximize the Minimum Distance.cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int SIZE = 10000;
const int XMAX = 0x7fffffff;
int amount, num[SIZE];
int pre[3], nxt[3];
int imin( int a, int b ) { return a<b?a:b; }
int imax( int a, int b ) { return a>b?a:b; }
int main() {
	while( scanf( "%d", &amount ), amount ) {
		for( int i=0; i<amount; ++i )
			scanf( "%d", num+i );
		sort( num, num+amount );
		pre[0] = pre[1] = pre[2] = XMAX;
		for( int i=1; i<amount; ++i ) {
			memset( nxt, 0, sizeof(nxt) );
			for( int k=0; k<9; ++k ) {
				int pa, pb, dd;
				pa = k/3; pb = k%3;
				dd = num[i]-num[i-1]+pb-pa;
				nxt[pb] = imax( nxt[pb], imin(dd,pre[pa]) );
			}
			memcpy( pre, nxt, 12 );
		}
		printf( "%d\n", imax( pre[0], imax(pre[1],pre[2]) ) );
	}
}