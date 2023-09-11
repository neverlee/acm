//10034-牛场围栏.cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

int amount, cut, mod;
int leng[3000];
int ref[3000];
void noret() {
	puts("-1");
	exit(0);
}
struct Cmp{
	bool operator()( const int &ia, const int &ib ) {
		return leng[ia]>leng[ib];
	}
};
int main() {
	scanf( "%d%d", &amount, &cut );
	for( int i=0; i<amount; ++i )
		scanf( "%d", leng+i );
	sort( leng, leng+amount );
	mod = leng[0]-cut;
	if( mod<2 ) noret();
	memset( ref, -1, sizeof(ref) );
	for( int i=0; i<amount; ++i )
		for( int j=leng[i]-cut; j<=leng[i]; ++j ) {
			int k = j%mod;
			if( ref[k]==-1 || ref[k]>j ) ref[k] = j;
		}
	memcpy( leng, ref, sizeof(int)*mod );
	priority_queue<int, vector<int>, Cmp> myq;
	for( int i=1; i<mod; ++i )
		if( leng[i]!=-1 ) myq.push( i );
	while( !myq.empty() ) {
		int pk;
		pk = myq.top();
		while( !myq.empty() && myq.top()==pk ) myq.pop();
		for( int i=0; i<mod; ++i )
		if( ref[i]!=-1 ) {
			int pi, tmp;
			pi = (pk+i)%mod;
			tmp = leng[pk]+ref[i];
			if( leng[pi]==-1 || leng[pi]>tmp ) {
				leng[pi] = tmp;
				myq.push( pi );
			}
		}
	}
	bool isno=false;
	int imax = 0;
	for( int i=0; i<mod; ++i ) {
		if( leng[i]>imax ) imax=leng[i];
		if( leng[i]==-1 ) isno = true;
	}
	if( isno || imax-mod<1 ) noret();
	printf( "%d", imax-mod );
}


