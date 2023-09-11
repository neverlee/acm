#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class MergeSet{
protected:
	int data[301];
public:
	MergeSet( ) {
		int i;
		for( i=0; i<=300; ++i )
			data[i]=i;
	}
	int find( int n ) {
		if( n==data[n] ) return n;
		else return ( data[n] = find( data[n] ) );
	}
	bool isConnected( int a, int b ) {
		return find(a) == find(b);
	}
	void merge( int a, int b ) {
		data[find(a)] = find(b);
	}
};

struct Node{
	int toa, tob;
	int val;
	friend bool operator<( const Node &na, const Node &nb ) {
		return na.val<nb.val;
	}
};

vector<Node> road;
vector<bool> can;
vector<Node> dist;
int ncity, nroad, time, aday, chg, ndist;
void init() {
	scanf( "%d%d%d%d%d", &ncity, &nroad, &time, &aday, &chg );
	road.resize(nroad);
	can.resize(nroad);
	int i, j;
	for( i=0; i<nroad; ++i ) {
		scanf( "%d%d%d", &road[i].toa, &road[i].tob, &road[i].val );
		if( road[i].toa>road[i].tob )
			swap( road[i].toa, road[i].tob );
	}
	sort( road.begin(), road.end() );
	scanf( "%d", &ndist );
	dist.resize( ndist );
	int x, y, ad, bd;
	for( i=0; i<ndist; ++i ) {
		scanf( "%d%d%d%d", &x, &y, &ad, &bd );
		if( x>y ) swap( x, y );
		for( j=0; j<nroad; ++j )
			if( x==road[j].toa && y==road[j].tob )
				break;
		dist[i].val = j;
		dist[i].toa = ad;
		dist[i].tob = bd;
	}
}

int kruskal() {
	MergeSet mset;
	int i, used, pay;
	for( i=0, used=0, pay=0; i<nroad&&used<ncity; ++i )
	if( can[i] ) {
		if( !mset.isConnected( road[i].toa, road[i].tob ) ) {
			mset.merge( road[i].toa, road[i].tob );
			++used;
			pay+=road[i].val;
		}
	}
	if( used==ncity-1 ) return pay;
	else return -1;
}

int cons[51][51];
void init_consume() {
	int i, j, k;
	for( i=1; i<=time; ++i )
		for( j=i; j<=time; ++j ) {
			fill( can.begin(), can.end(), true );
			for( k=0; k<dist.size(); ++k ) {
				if( !( j<dist[k].toa || i>dist[k].tob ) )
					if( dist[k].val<can.size() ) 
					can[dist[k].val]=false;
			}
			cons[i][j] = kruskal();
			//if( cons[i][j] != -1 )
			//printf( "%d,%d - %d\n", i, j, cons[i][j] );
		}
}

int f[51];
void dp() {
	f[0]=0;
	int i, j, k;
	const int MMAX = 0x7fffffff;
	for( i=1; i<=time; ++i ) {
		f[i] = MMAX;
		for( j=0; j<i; ++j ) {
			if( cons[j][i]==-1 ) continue;
			k = f[j] + chg + aday*cons[j+1][i]*(i-j);
			f[i] = f[i]<k?f[i]:k;
		}
	}
	printf( "%d", f[time] );
}

int main() {
	init();
	init_consume();
	dp();
	return 0;
}