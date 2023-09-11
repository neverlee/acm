#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Graphic{
	bool data[10][10];
	bool used[10];
	int size, remain, ret;
public:
	Graphic() {
		int gap, high[10];
		int i, j, k;
		scanf( "%d%d", &size, &gap );
		for( i=0; i<size; ++i )
			scanf( "%d", high+i );
		memset( data, 1, sizeof(data) );
		memset( used, 0, sizeof(used) );
		for( i=0; i<size; ++i )
			for( j=0; j<size; ++j ) {
				k = high[i]-high[j];
				k = k>=0?k:-k;
				if( i==j || k>gap ) data[i][j]=0;
			}
	}
	void work() {
		if( size==1 ) {
			putchar('1');
			return;
		}
		remain = size-1;
		ret = 0;
		used[0]=1;
		visit( 0 );
		printf( "%d", ret );
	}
	void visit( int p ) {
		if( remain==0 ) {
			if( data[p][0] )
				++ret;
			return;
		}
		int i;
		for( i=0; i<size; ++i )
		if( used[i]==0 && data[p][i] ) {
			used[i]=1; --remain;
			visit( i );
			used[i]=0; ++remain;
		}
	}
};

int main() {
	Graphic myg;
	myg.work();
	return 0;
}