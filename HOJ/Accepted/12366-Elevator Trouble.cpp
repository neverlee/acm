//12366-Elevator Trouble.cpp
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int f, s, g, u, d;
const int SIZE = 1000001;
int t[SIZE];

int bfs() {
	memset( t, -1, sizeof(t) );
	queue<int> qi;
	qi.push(s);
	t[s] = 0;
	while( !qi.empty() ) {
		int p, n;
		p = qi.front();
		if( p==g ) return t[p];
		n = p+u;
		if( n<=f && t[n]==-1 ) {
			t[n] = t[p]+1;
			qi.push( n );
		}
		n = p-d;
		if( n>0 && t[n]==-1 ) {
			t[n] = t[p]+1;
			qi.push( n );
		}
		qi.pop();
	}
	return -1;
}

int main() {
	while( EOF != scanf( "%d%d%d%d%d", &f, &s, &g, &u, &d ) ) {
		int ret = bfs();
		if( ret==-1 ) puts( "use the stairs" );
		else printf( "%d\n", ret );
	}
}


