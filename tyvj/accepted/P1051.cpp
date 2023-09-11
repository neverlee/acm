#include <cstdio>
#include <cstring>
class Node {
public:
	int value;
	Node *son, *brother;
	Node( int v=0, Node *s=NULL, Node *b=NULL ) {
		value = v;
		son = s;
		brother = b;
	}
};
class BTree {
	int total, limit;
	Node node[301];
	int f[301][301];
public:
	void init() {
		scanf( "%d%d", &total, &limit );
		int i, pre;
		for( i=1; i<=total; ++i ) {
			scanf( "%d%d", &pre, &node[i].value );
			if( node[pre].son ) {
				Node *p = node[pre].son;
				for( ; p->brother; p=p->brother );
				p->brother = node+i;
			}else {
				node[pre].son = node+i;
			}
		}
		++limit;
	}
	int getSon( Node *p, int k ) {
		if( k==1 ) return node[p-node].value;
		if( p->son==NULL || k==0 ) return 0;
		int ison = p->son - node;
		return f[ison][k-1] + node[p-node].value;
	}
	int getBrother( Node *p, int k ) {
		if( p->brother==NULL ) return 0;
		int ib = p->brother - node;
		return f[ib][k];
	}
	void imax( int &a, int b ) { a=a>b?a:b; }
	void preVisit( Node *p ) {
		if( p==NULL ) return;
		preVisit( p->son );
		preVisit( p->brother );
		int ime;
		ime = p - node;
		int i, j;
		for( i=1; i<=limit; ++i ) {
			for( j=0; j<=i; ++j )
				imax( f[ime][i], getSon( p, j ) + getBrother( p, i-j ) );
		}
	}
	void dp() {
		int i, j;
		memset( f, 0, sizeof(f) );
		for( i=1; i<=total; ++i )
			f[i][1] = node[i].value;
		preVisit( node );
		printf( "%d\n", f[0][limit] );
	}
};
int main() {
	BTree bt;
	bt.init();
	bt.dp();
	return 0;
}