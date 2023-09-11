#include <cstdio>

static const int SIZE = 280000;
static const int NOELE = 0x7fffffff;
	int size, bsize, opt;
	int data[SIZE], *first;
	int left, right;
class LineTree{
public:
	int imin( int a, int b ) { return a<b?a:b; }
	void init() {
		scanf( "%d%d", &size, &opt );
		for( bsize=1; bsize<=size; bsize<<=1 );
		first = data+bsize;
		int i;
		for( i=0; i<bsize; ++i ) {
			first[i]=NOELE;
			if( i<size ) scanf( "%d", first+i ) ;
		}
		for( i=bsize-1; i>0; --i )
			data[i] = imin( data[i<<1], data[(i<<1)+1] );
	}
	int queryMin( int pos, int st, int ed ) {
		if( left<=st&&right>=ed )
			return data[pos];
		if( left>=ed || right<=st ) return NOELE;
		return imin( queryMin( pos*2, st, (st+ed)/2 )
				, queryMin( pos*2+1, (st+ed)/2, ed ) );
	}
	void change( int pos, int act ) {
		pos = bsize+pos-1;
		data[pos] = act;
		for( pos>>=1; pos>0; pos>>=1 ) {
			data[pos] = imin( data[pos<<1], data[(pos<<1)+1] );
		}
	}
	void work() {
		int s, st, ed;
		while( opt-- ) {
			scanf( "%d%d%d", &s, &st, &ed );
			left = st-1;
			right = ed;
			if( s==1 ) {
				printf( "%d ", queryMin( 1, 0, bsize ) );
			}else {
				change( st, ed );
			}
		}
	}
};

int main() {
	LineTree ltLoy;
	ltLoy.init();
	ltLoy.work();
	return 0;
}


