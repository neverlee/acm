// 此题 用于练习下堆操作及堆排序
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 10001;
class Heap {
protected:
	int data[SIZE];
	void adjust( int i, int len ) {
		int cl, tmp;
		for( tmp = data[i]; (i<<1)<=len; i=cl ) {
			cl = (i<<1);
			if( cl<len && data[cl]<data[cl+1] ) ++cl;
			if( tmp<data[cl] )
				data[i] = data[cl];
			else break;
			data[cl] = tmp;
		}
	}
	int egis( int n ) {
		int cl=(n<<1);
		if( cl<data[0] && data[cl]>data[cl+1] ) ++cl;
		if( data[n]>data[cl] )
			swap( data[n], data[cl] );
		return cl;
	}
public:
	void input() {
		int i;
		scanf( "%d", data+0 );
		for( i=1; i<=data[0]; ++i )
			scanf( "%d", data+i );
	}
	int pop_head() {
		int head = data[1];
		data[1] = data[data[0]];
		--data[0];
		int i;
		for( i=1; (i<<1)<=data[0]; i=egis(i) );
		return head;
	}
	void insert( int num ) {
		data[++data[0	]] = num;
		int i;
		for( i=data[0]/2; i>0; i>>=1 ) egis(i);
	}
	void sort() {
		int i;
		for( i=data[0]/2; i>0; --i)
			adjust( i, data[0] );
		for( i=data[0]; i>1; --i) {
			swap( data[1], data[i] );
			adjust( 1, i-1 );
		}
	}
	int merge() {
		int a, sum;
		sum = 0;
		while( data[0]>1 ) {
			a = pop_head();
			a += pop_head();
			insert( a );
			sum += a;
		}
		return sum;
	}
};

int main() {
	Heap myh;
	myh.input();
	myh.sort();
	printf( "%d", myh.merge() );
	return 0;
}