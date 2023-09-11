#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int SIZE = 1000;
int amount, num[SIZE];

struct Node{
	int to;
	Node *next;
	Node( int t=-1, Node *n=NULL ) { to=t; next=n; }
	void set( int t=-1, Node *n=NULL ) { to=t; next=n; }
}erp[1000];

void init() {
	int i, j;
	int f[SIZE];
	scanf( "%d", &amount );
	for( i=0; i<amount; ++i )
		scanf( "%d", num+i );
	f[amount-1] = num[amount-1];
	for( i=amount-2; i>=0; --i )
		f[i] = num[i]<f[i+1]?num[i]:f[i+1];
	for( i=0; i<amount-2; ++i )
		for( j=i+1; j<amount-1; ++j )
			if( num[i]<num[j] && num[i]>f[j+1] ) {
				erp[i].next = new Node( j, erp[i].next );
				erp[j].next = new Node( i, erp[j].next );
			}
}

bool dye_fail;
void dyeing( int pi, int stt ) {
	if( dye_fail ) return;
	if( erp[pi].to==-1 ) {
		erp[pi].to = stt;
		Node *p;
		p = erp[pi].next;
		for( ; p; p=p->next )
			dyeing( p->to, 1-stt );
	}
	if( erp[pi].to!=stt )
		dye_fail=1;
}

char ret[2000];
int ri;
void tsort() {
	int i, j;
	const int SEND = 0x00ffffff;
	stack<int> st[2];
	st[0].push( SEND );
	st[1].push( SEND );
	ri=0;
	for( i=0; i<amount; ) {
		int at;
		at = erp[i].to;
		if( num[i]<st[at].top() ) {
			st[at].push( num[i] );
			ret[ri++] = 'a'+2*at;
			++i;
		}else if( num[i]>st[at].top() ) {
			ret[ri++] = 'b'+2*at;
			st[at].pop();
		}
	}
	while( st[0].top()!=SEND || st[1].top()!=SEND ) {
		if( st[0].top()<st[1].top() ) {
			ret[ri++] = 'b';
			st[0].pop();
		}else {
			ret[ri++] = 'd';
			st[1].pop();
		}
	}
	for( i=1; i<ri; ++i )
		for( j=i; j>0 ; --j )
		if( (ret[j-1]=='d'&&ret[j]=='a')||(ret[j-1]=='c'&&ret[j]=='b') )
			swap( ret[j], ret[j-1] );
		else break;
	for( i=0; i<ri; ++i ) {
		if( i ) putchar(' ');
		putchar( ret[i] );
	}
}

int main() {
	int i;
	init();
	dye_fail = 0;
	for( i=0; i<amount; ++i )
	if( erp[i].next!=NULL && erp[i].to==-1 )
		dyeing( i, 0 );
	if( !dye_fail ) {
		for( i=0; i<amount; ++i )
		if( erp[i].to==-1 )
			erp[i].to=0;
	}
	if( dye_fail ) putchar('0');
	else tsort();
}





