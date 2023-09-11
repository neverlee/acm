#include <cstdio>
#include <cmath>
#include <vector>

const int LIMIT = 50000;

struct Factor{
	int base, exp;
	void set( int b, int e ) { base=b; exp=e; }
}fact[40];
int len;

void divnum( int nn ) {
	int i, k;
	len = 0;
	for( i=2; i<=nn&&i<=LIMIT; ++i )
	if( nn%i==0 ) {
		k=0;
		while( nn%i==0 ) { ++k; nn/=i; }
		fact[len++].set( i, k );
	}
	if( nn>1 )
		fact[len++].set( nn, 1 );
}

int test( int nn ) {
	int i, b, imax, d, k;
	imax = 0;
	for( i=0; i<len; ++i ) {
		b = fact[i].base;
		if( nn%b==0 ) {
			k=0;
			while( nn%b==0 ) { ++k; nn/=b; }
			d = fact[i].exp/k + (fact[i].exp%k>0?1:0) ;
			imax = d>imax?d:imax;
		}else return -1;
	}
	return imax;
}

int main() {
	int nc, ma, mb, in;
	scanf( "%d%d%d", &nc, &ma, &mb );
	divnum( ma );
	for( in=0; in<len; ++in ) fact[in].exp*=mb;
	ma = -1;
	while( nc-- ) {
		scanf( "%d", &in );
		mb = test(in);
		if( ma==-1 || (mb!=-1&&mb<ma) ) ma = mb;
	}
	printf( "%d", ma );
}
