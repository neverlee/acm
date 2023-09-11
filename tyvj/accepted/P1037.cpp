#include <cstdio>
__int64 fact, lmod, bmd;
int main() {
	int n,k;
	scanf( "%d%d", &n, &k );
	fact=lmod=1;
	int i;
	for( i=0; i<k; ++i ) lmod*=10;
	bmd = lmod * 100;
	for( i=2; i<=n; ++i ) {
		int k=i;
		while( k%10==0 ) k/=10;
		while( k%5==0 ) {
			fact/=2;
			k/=5;
		}
		fact *= k;
		fact %= bmd;
	}
	char str[20];
	sprintf( str, "%%0%dI64d", k );
	printf( str, fact%lmod );
	return 0;
}

