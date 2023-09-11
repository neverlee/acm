#include <cstdio>

int main() {
	int nc; scanf( "%d", &nc );
	int k, s, t;
	while( nc-- ) {
		scanf( "%d", &k );
		s=0;
		for( int i=0; i<k; ++i ) {
			scanf( "%d", &t );
			s+=t;
		}
		s -= (k-1);
		printf( "%d\n", s );
	}
}
