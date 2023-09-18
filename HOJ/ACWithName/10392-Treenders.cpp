//10392-Treenders.cpp
#include <cstdio>
int ret[2001]={0,0,0,0,2,5};
int main() {
	int i, d, t;
	for( i=6; i<=2000; ++i ) {
		d = i/2;
		if( i%2==1 )
			ret[i] = i*(d*(d-1)/2);
		else 
			ret[i] = d*(d*(d-1)/2)+d*((d-2)*(d-1)/2);
	}
	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d", &d );
		printf( "%d\n", ret[d] );
	}
}