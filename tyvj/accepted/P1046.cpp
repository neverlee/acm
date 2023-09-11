#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int lmin( int amount, ... ) {
	va_list pArg;
	int nMin=0x7fffffff, n;
	va_start( pArg, amount );
	while( amount-- ) {
		n = va_arg( pArg, int );
		nMin = nMin<n?nMin:n;
	}
	va_end( pArg );
	return nMin;
}
char stra[2010], strb[2010];
int la, lb;
int kist;
void init() {
	gets( stra+1 );
	gets( strb+1 );
	scanf( "%d", &kist );
	la = strlen( stra+1 )+1;
	lb = strlen( strb+1 )+1;
}
int f[2][2010], *pa, *pb;
void dp() {
	pa=f[0]; pb=f[1];
	int i, j;
	for( i=1; i<lb; ++i ) pa[i]=kist*i;
	for( i=1; i<la; ++i ) {
		pb[0]=i*kist;
		for( j=1; j<lb; ++j ) {
			pb[j] = lmin( 3, pa[j-1]+abs(stra[i]-strb[j])
							, pa[j]+kist, pb[j-1]+kist );
		}
		swap( pa, pb );
	}
	printf("%d", pa[lb-1] );
}
int main() {
	init();
	dp();
	return 0;
}