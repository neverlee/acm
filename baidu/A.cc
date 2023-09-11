#include <cstdio>

int can, amount;
int u, d, dv;
int main() {
	scanf( "%d%d", &can, &amount );
	int imin = 0x7fffffff;
	while( amount-- ) {
		scanf( "%d%d", &u, &d );
		int low, high, mid;
		low = 0; high = can;
		int lu, ld;
		while( low<high ) {
			mid = (low+high)/2;
			lu = mid * u;
			ld = (can-mid) * d;
			if( lu<ld ) low = mid+1;
			else high = mid;
		}
		while( low>0 && (low*u-(can-low)*d) >= 0 ) --low;
		while( low<can && (low*u-(can-low)*d) < 0 ) ++low;
		dv = low*u - (can-low)*d;
		if( dv<imin ) imin = dv;
	}
	printf( "%d", imin );
}
