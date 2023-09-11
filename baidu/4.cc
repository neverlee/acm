#include <cstdio>

int main() {
	int nc; scanf( "%d", &nc );
	while( nc-- ) {
		int h, m;
		scanf( "%d:%d", &h, &m );
		h+=12;
		if( h>24 ) h-=24;
		if( m ) puts("0");
		else printf( "%d\n", h );
	}
}
