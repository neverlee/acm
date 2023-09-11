#include <cstdio>
#include <stack>
#include <cctype>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

const char cmp[8][8] = {//>pop <push
	//+	  -    *   /   ^    (   )    0
	{'>','>','<','<','<','<','>','>'},// +
	{'>','>','<','<','<','<','>','>'},// -
	{'>','>','>','>','<','<','>','>'},// *
	{'>','>','>','>','<','<','>','>'},// /
	{'>','>','>','>','>','<','>','>'},// ^
	{'<','<','<','<','<','<','=','>'},// (
	{'>','>','>','>','>','>','>','>'},// )
	{'<','<','<','<','<','<','>','='} // 0
};
int trans(char c) {
	switch(c) {
	case '+': return 0;
	case '-': return 1;
	case '*': return 2;
	case '/': return 3;
	case '^': return 4;
	case '(': return 5;
	case ')': return 6;
	case 0  : return 7;
	default:return 9;
	}
}
int acalu( int a, int b, char o ) {
	int d;
	switch(o) {
	case 0: return a+b;
	case 1: return a-b;
	case 2: return a*b;
	case 3: return a/b;
	case 4:
		for( d=1; b; a*=a, b>>=1)
			if( b&0x00000001 ) d*=a;
		return d;
	}
}

stack<char> opt;
char sexp[400], *p;
vector<int> onum;
vector<bool> type;
int getInt() {
	int k=0;
	for( ; isdigit(*p); ++p )
		k = k*10+*p-'0';
	return k;
}

void init() {
	char str[100];
	gets( str );
	int i,j;
	for( i=0,j=0; str[i]; ) {
		if( str[i]=='-' && (i<=0||str[i-1]=='(') )
			sexp[j++]='0';
		sexp[j++]=str[i++];
	}
	p = sexp;
	onum.reserve( 200 );
	type.reserve( 200 );
}
void mtor() {
	opt.push(7);
	int dn;
	char o;
	while( !opt.empty() ) {
		while( isspace(*p) ) ++p;
		if( isdigit(*p) ) {
			dn = getInt();
			onum.push_back( dn );
			type.push_back( 0 );
		}else {
			o = trans(*p);
			switch( cmp[opt.top()][o] ) {
			case '<':
				opt.push( o );
				++p;
				break;
			case '=':
				++p;
				opt.pop();
				break;
			case '>':
				dn = opt.top();
				opt.pop();
				if( dn>4 ) break;
				onum.push_back( dn );
				type.push_back( 1 );
				break;
			}
		}
	}
	int i, top;
	for( i=0, top=-1; i<onum.size(); ++i ) {
		if( type[i]&&onum[i]<5 ) {
			onum[top-1] = acalu( onum[top-1], onum[top], onum[i] );
			--top;
		}else onum[++top] = onum[i];
	}
	printf( "%d", onum[0] );
}
int main() {
	init();
	mtor();
	return 0;
}
