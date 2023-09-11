#include <cstdio>
#include <queue>
using namespace std;

const int NUM = 100010;
int ncity, nroad;
int price[NUM];

struct Node{
	int to;
	Node *next;
	Node( int t, Node *n=NULL ) {
		to = t;
		next = n;
	}
	Node() {
		next = NULL;
	}
};

Node map[NUM];

void input() {
	scanf( "%d%d", &ncity, &nroad );
	for( int i=1; i<=ncity; ++i )
		scanf( "%d", &map[i].to );
	int x, y, z;
	for( int i=0; i<nroad; ++i ) {
		scanf( "%d%d%d", &x, &y, &z );
		map[x].next = new Node( y, map[x].next );
		if( z==2 )
			map[y].next = new Node( x, map[y].next );
	}
}

int low[NUM];

void bfs() {
	for( int i=1; i<=ncity; ++i )
		low[i]=0x7fFfFfff;
	low[1] = map[1].to;
	queue<int> tq;
	tq.push(1);
	while( !tq.empty() ) {
		int pre, nxt;
		pre = tq.front();
		tq.pop();
		for( Node *p = map[pre].next; p; p=p->next ) {
			nxt = p->to;
			if( low[pre]<low[nxt] || low[nxt]>map[nxt].to ) {
				low[nxt] = low[pre]<map[nxt].to?low[pre]:map[nxt].to;
				tq.push( nxt );
			}
		}
	}
	for( int i=1; i<=ncity; ++i ) {
		map[i].to = map[i].to-low[i];
		low[i] = 0;
	}
	tq.push(1);
	while( !tq.empty() ) {
		int pre, nxt;
		pre = tq.front();
		tq.pop();
		for( Node *p = map[pre].next; p; p=p->next ) {
			nxt = p->to;
			if( low[pre]>low[nxt] || low[nxt]<map[nxt].to ) {
				low[nxt] = low[pre]>map[nxt].to?low[pre]:map[nxt].to;
				tq.push( nxt );
			}
		}
	}
}

int main() {
	input();
	bfs();
	printf( "%d", low[ncity]>0?low[ncity]:0 );
}









