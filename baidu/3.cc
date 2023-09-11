#include <cstdio>

int main() {
	double sum, t;
	sum=0;
	for( int i=0; i<12; ++i ) {
		scanf( "%lf", &t );
		sum += t;
	}
	sum /= 12.0;
	printf( "$%.2lf", sum );
}
