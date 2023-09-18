//11436-梁山好汉排座次.cpp
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
char stra[10], strb[10];
int kdx;
bool rect[108][108];
map<string, int> ref;
char name[108][10];
int get_id( char *s ) {
	string str(s);
	if( ref.find( str ) == ref.end() ) {
		ref[str] = kdx++;
		return kdx-1;
	}else return ref[str];
}
void topo_sort() {
	int into[108], last[108];
	memset( into, 0, sizeof(into) );
	memset( last, -1, sizeof(last) );
	for( int i=0; i<kdx; ++i )
		for( int j=0; j<kdx; ++j )
		if( rect[i][j] ) ++into[i];
	for( int i=0; i<kdx; ++i ) {
		int k;
		for( k=0; into[k]!=0&&k<kdx; ++k );
		if( k==kdx ) return;
		last[i] = k;
		for( int j=0; j<kdx; ++j )
			if( rect[j][k] ) --into[j];
		into[k] = -1;
	}
	map<string, int>::iterator it;
	for( it=ref.begin(); it!=ref.end(); ++it ) {
		strcpy( name[it->second], (it->first).c_str() );
	}
	for( int i=0; i+1<kdx; ++i ) {
		printf( "%s ", name[last[i]] );
	}
	printf( "%s\n", name[last[kdx-1]] );
}
int main() {
	int amount;
	while( scanf( "%d", &amount ), amount ) {
		ref.clear();
		kdx=0;
		memset( rect, 0, sizeof(rect) );
		while( amount-- ) {
			scanf( "%s%s", stra, strb );
			int ia, ib;
			ia = get_id(stra);
			ib = get_id(strb);
			rect[ib][ia]=1;
		}
		topo_sort();
	}
}