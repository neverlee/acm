//12359-User Names.cpp
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char str[90], rdy[90];
char name[200][90];
int have[200];
int maxl, amount, store;

int make_name() {
	int p, i;
	for( p=0; str[p]&&!isalpha(str[p]); ++p );
	rdy[0] = str[p];
	for( p=strlen(str); str[p]!=' '; --p );
	for( i=1, ++p; str[p]; ++p )
		if( isalpha(str[p]) )
			rdy[i++] = str[p];
	rdy[i] = 0;
	rdy[maxl] = 0;
	for( int i=0; rdy[i]; ++i )
		if( isupper(rdy[i]) )
			rdy[i]+=32;
	return maxl<i?maxl:i;
}

int exists() {
	for( int i=0; i<store; ++i )
		if( strcmp( rdy, name[i] ) == 0 ) return i;
	return -1;
}

int main() {
	for( int T=1; scanf( "%d%d%*c", &amount, &maxl ), amount>0; ++T ) {
		printf( "Case %d\n", T );
		memset( have, 0, sizeof(have) );
		store=0;
		while( amount-->0 ) {
			gets( str );
			int l = make_name(), ext;
			if( (ext=exists()) == -1 ) {
				strcpy( name[store++], rdy );
				puts( rdy );
			}else {
				++have[ext];
				int w,k;
				w = have[ext]>9?2:1;
				if( l+w>maxl ) k=maxl-w;
				else k=l;
				sprintf( rdy+k, "%d", have[ext] );
				puts( rdy );
			}
		}
	}
}
				


