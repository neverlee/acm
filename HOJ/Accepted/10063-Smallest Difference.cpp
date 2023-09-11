//10063-Smallest Difference.cpp
#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;

int cnt, len;
char str[25];
int iabs( int a ) { return a>=0?a:-a; }
void deal_lit() {
	cnt = 0;
	for( int i=0, j=0; i<len; ++i )
		if( isdigit( str[i] ) ) {
			char tc;
			tc = str[i];
			str[j++] = tc;
			++cnt;
		}
}
int get_small( int last ) {
	for( int i=-1, j=cnt; ; ) {
		while( !isdigit(str[++i]) );
		while( !isdigit(str[--j]) );
		if( i>=j ) break;
		last = iabs( last*10 );
		last-=iabs( str[i]-str[j] );
	}
	return iabs(last);
}
void deal() {
	int ret=0x7fffffff, pi, last;
	gets( str );
	len = strlen( str );
	deal_lit();
	if( str[0]=='0' ) pi=2;
	else pi=1;
	if( cnt%2==1 ) {
		last = str[pi-1]-'0';
		str[pi-1]=-1;
		ret = get_small( last );
	}else {
		int p;
		last = 100;
		if( cnt==2 ) {
			printf( "%d\n", iabs( str[0]-str[1] ) );
			return;
		}
		for( int i=pi; i<cnt; ++i ) {
			int k;
			k = iabs( str[i]-str[i-1] );
			if( k<last ) {
				last = k;
				p = i;
			}
		}
		for( int i=pi; i<cnt; ++i )
		if( iabs( str[i]-str[i-1] )==last ) {
			str[i]=-str[i];
			str[i-1]=-str[i-1];
			int k = get_small( last );
			if( k<ret ) ret = k;
			str[i]=-str[i];
			str[i-1]=-str[i-1];
		}
	}
	printf( "%d\n", ret );
}
int main() {
	int ntst;
	scanf( "%d%*c", &ntst );
	while( ntst-- ) {
		deal();
	}
}
