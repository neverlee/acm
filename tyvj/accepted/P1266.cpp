#include <cstdio>
#include <cstring>

const int MMAX = 0x7fFfFfFf;
int chg[25];
void init_chg() {
	int bit[7];
	int i, k;
	for( k=0; k<25; ++k ) {
		int x, y, r;
		x=k/5+1; y=5-k%5;
		memset( bit, 0, sizeof(bit) );
		bit[x+1] = ( bit[x-1] |= (1<<y) );
		bit[x] |= (7<<(y-1));
		for( i=1, r=0; i<=5; ++i )
			r = (r<<5)+((bit[i]>>1)&31);
		chg[k] = r;
	}
}

int line[32], foot[32];
void init_line() {
	int i, k;
	for( k=0; k<32; ++k ) {
		int m, c, r;
		m=k; c=0; r=(1<<25)-1;
		for( i=0; i<5; ++i, m>>=1 ) {
			if( m&1 ) {
				++c;
				r ^= chg[i];
			}
		}
		line[k] = r;
		foot[k] = c;
	}
}

int from_str( char *ss ) {
	int i, r;
	for( r=0, i=0; ss[i]; ++i )
		r = (r<<1)+(ss[i]=='1'?1:0);
	return r;
}

int search( int ncy ) {
	int i, k, t, f, imin;
	imin = MMAX;
	for( k=0; k<32; ++k ) {
		t=line[k]; f=foot[k];
		int m;
		for( i=0, m=1<<24; i<20&&f<6; ++i, m>>=1 ) {
			if( (t&m)!=(ncy&m) ) {
				t ^= chg[i+5];
				++f;
			}
			if( t==ncy && imin>f ) {
				imin=f;
				break;
			}
		}
	}
	return imin;
}

int main() {
	init_chg();
	init_line();
	int icase;
	scanf( "%d", &icase );
	char str[40];
	int i;
	while( icase-- ) {
		for( i=0; i<25; i+=5 )
			scanf( "%s", str+i );
		int ncy, k;
		ncy = from_str( str );
		k = search( ncy );
		if( k==MMAX ) k=-1;
		printf( "%d\n", k );
	}
}
