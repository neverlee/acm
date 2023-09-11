#include <cstdio>
int max_power, miter_amount;
bool maps[11][11];
struct Node{
	int power, load;
};
Node miter[11];
bool been[11];
int last, lmax;
int set[11];
int load[11];
int mode[11];
int find( int n ) {
	if( set[n]==n ) return n;
	else return set[n] = find( set[n] );
}
void init() {
	int i, j, n;
	scanf( "%d%d%d", &max_power, &miter_amount, &n );
	for( i=1; i<=miter_amount; ++i ) {
		scanf( "%d%d", &miter[i].power, &miter[i].load );
		miter[i].power/=100;
	}
	int ca, cb;
	for( i=1; i<=miter_amount; ++i ) {
		set[i] = i;
		load[i] = miter[i].load;
	}
	for( i=1; i<=miter_amount; ++i ) maps[i][i] = 1;
	for( i=0; i<n; ++i ) {
		scanf( "%d%d", &ca, &cb );
		if( find(ca)!=find(cb) ) {
			load[ find(cb) ] += load[ find(ca) ];
			set[ find(ca) ] = find(cb);
		}
	}
	for( i=1; i<=miter_amount; ++i )
		find(i);
}
void dg( int lv, int rmpower ) {
	int i, j, kl;
	if( lv>miter_amount ) return;
	for( i=1; i<=miter_amount; ++i )
	if( been[i]==0 ) {
		int idx = set[i];
		int need = miter[i].power * (100+mode[idx]);
		if( rmpower>=need ) {
			kl = load[idx];
			been[i]=1;
			++mode[idx];
			load[idx] -= miter[i].load;
			last += kl;
			if( lmax<last ) lmax = last;
			dg( lv+1, rmpower-need );
			load[idx] += miter[i].load;
			--mode[idx];
			last -= kl;
			been[i]=0;
		}
	}
}

int main() {
	init();
	dg( 1, max_power );
	printf( "%d", lmax );
}
