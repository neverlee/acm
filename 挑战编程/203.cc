#include <cstdio>
int nday, nh;
int h[200];
void deal() {
	int lost, i, j;
	scanf( "%d%d", &nday, &nh );
	for( i=0; i<nh; ++i )
		scanf( "%d", h+i );
	for( lost=0, i=0; i<nday; i++)
	if ( i%7!=5 && i%7!=6 ) {
		for( j=0; j<nh; j++ )
		if( (i+1)%h[j] == 0 ) {
			++lost;
			break;
		}
	}
	printf( "%d\n", lost );
}
int main() {
	int ntxt;
	scanf( "%d", &ntxt );
	while( ntxt-- )
		deal();
	return 0;
}