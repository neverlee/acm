#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const __int64 UNLIMIT = (__int64)0x0fffffff*0x00100000;
__int64 dist[1001];
struct cmp{
	bool operator()( const int &ia, const int &ib ) {
		return dist[ia]>dist[ib];
	}
};
//class Maps{
int planet_amount, target_planet;
int maps[1001][1001];
void init() {
	int track_amount;
	int i, j;
	scanf( "%d", &planet_amount );
	scanf( "%d", &target_planet );
	scanf( "%d", &track_amount );
	memset( maps, -1, sizeof(maps) );
	int a, b ,c;
	while( track_amount-- ) {
		scanf( "%d%d%d", &a, &b, &c );
		if( maps[a][b]==-1 || c<maps[a][b] )
			maps[a][b]=maps[b][a]=c;
	}
}
priority_queue<int, vector<int>, cmp> hq;
void dijkstra() {
	int i;
	for( i=1; i<=planet_amount; ++i ) dist[i]=UNLIMIT;
	dist[ target_planet ] = 0;
	hq.push( target_planet );
	while( !hq.empty() ) {
		int now;
		now = hq.top();
		hq.pop();
		for( i=1; i<=planet_amount; ++i )
		if( maps[now][i]!=-1 ) {
			__int64 k = dist[now]+maps[now][i];
			if( k<dist[i] ) {
				dist[i] = k;
				hq.push( i );
			}
		}
	}
	dist[0]=0;
	for( i=1; i<=planet_amount; ++i )
		dist[0]+=dist[i];
}
//};
int main() {
	init();
	dijkstra();
	if( dist[0]<UNLIMIT ) printf( "%I64d M(s) are needed.", dist[0] );
	else puts("Sth wrong.");
	return 0;
}