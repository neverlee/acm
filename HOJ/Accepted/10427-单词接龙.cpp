//10427-单词接龙.cpp
#include <cstdio>
#include <cstring>

const int MMAX = 0x0fffffff;
char word[20][40];
int amount, ret;
struct Node{
	int len, to;
	Node *next;
	Node() { next=NULL; }
	void set( int l, int t, Node *n ) {
		len=l; to=t; next=n;
	}
	Node( int l, int t, Node *n=NULL ) {
		set( l, t, n );
	}
};
Node map[20];
int cancat( char *sf, int lf, char *ss, int ls ) {
	int min;
	min = lf<ls?lf:ls;
	for( int l=1; l<min; ++l ) {
		bool flag=1;
		for( int i=1; i<=l; ++i )
			if( sf[lf-l+i-1]!=ss[i-1] ) {
				flag=0;
				break;
			}
		if( flag==1 ) return l;
	}
	return MMAX;
}
void init() {
	scanf( "%d", &amount );
	for( int i=0; i<amount; ++i ) {
		scanf( "%s", word[i] );
		map[i].len = strlen( word[i] );
	}
	for( int i=0; i<amount; ++i )
		for( int j=0; j<amount; ++j ) {
			int kll;
			kll = cancat( word[i], map[i].len, word[j], map[j].len );
			if( kll!=MMAX ) {
				map[i].next = new Node( kll, j, map[i].next );
			}
		}
}
int can[20], recent;
void dfs( int pi ) {
	--can[pi];
	recent += map[pi].len;
	if( recent>ret ) ret=recent;
	Node *p;
	for( p = map[pi].next; p; p=p->next )
	if( can[p->to]>0 ) {
		recent -= p->len;
		dfs( p->to );
		recent += p->len;
	}
	recent -= map[pi].len;
	++can[pi];
}
void search() {
	ret=0;
	for( int i=0; i<amount; ++i )
		can[i] = 2;
	char cs;
	scanf( " %c", &cs );
	for( int i=0; i<amount; ++i )
		if( word[i][0]==cs ) {
			recent=0;
			dfs( i );
		}
	printf( "%d", ret );
}
int main() {
	init();
	search();
}
