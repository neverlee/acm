#include <cstdio>
#include <algorithm>
using namespace std;

struct MM{
	int at, rp;
	friend bool operator<( const MM &a, const MM &b ) {
		return a.at<b.at;
	}
};

MM mm[1001];
int nall, nat;
void init() {
	int i;
	scanf( "%d%d", &nall, &nat );
	for( i=1; i<=nall; ++i )
		scanf( "%d%d", &mm[i].at, &mm[i].rp );
	mm[nat].rp = -1;
	sort( mm+1, mm+nall+1 );
	for( nat=1; nat<=nall&&mm[nat].rp!=-1; ++nat );
	mm[nat].rp = 0;
	for( i=1; i<=nall; ++i )
		mm[i].rp += mm[i-1].rp;
}

int dest( int l, int r ) {
	return mm[r].at-mm[l].at;
}
int waste( int l, int r ) {
	return mm[l].rp+mm[nall].rp-mm[r-1].rp;
}

int la[1001][1001], ra[1001][1001];
int imin( int a, int b ) { return a<b?a:b; }
void dp() {
	int i, j, k;
	la[nat][nat] = ra[nat][nat] = 0;
	for( i=nat-1; i>0; --i ) {
		la[i][nat] = la[i+1][nat]+dest(i,i+1)*waste(i, nat+1);
		ra[i][nat] = la[i][nat]+dest(i,nat)*waste(i-1, nat+1);
	}
	for( i=nat+1; i<=nall; ++i ) {
		ra[nat][i] = ra[nat][i-1]+dest(i-1,i)*waste(nat-1, i);
		la[nat][i] = ra[nat][i]+dest(nat,i)*waste(nat-1, i+1);
	}
	for( i=nat-1; i>0; --i ) {
		for( j=nat+1; j<=nall; ++j ) {
			k = waste( i, j+1 );
			la[i][j] = imin( la[i+1][j]+dest(i, i+1)*k,
							 ra[i+1][j]+dest(i, j)*k );
			k = waste( i-1, j );
			ra[i][j] = imin( ra[i][j-1]+dest(j-1, j)*k,
							  la[i][j-1]+dest(i,j)*k );
		}
	}
	printf( "%d", imin( la[1][nall], ra[1][nall] ) );
}
int main() {
	init();
	dp();
	return 0;
}









