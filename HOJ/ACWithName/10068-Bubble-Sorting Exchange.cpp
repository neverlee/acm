//10068-Bubble-Sorting Exchange.cpp
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

const int SIZE = 500000;
int ff[2][SIZE], amount;
__int64 total;

int get_int() {
	int a, b;
	while( !isdigit(a=getchar()) );
	for( a-='0'; isdigit(b=getchar()); ) a=a*10+b-'0';
	return a;
}

int merge_sort( int left, int right ) {
	int mid, t=0;
	mid = (left+right)/2;
	if( left+2< right ) {
		t = merge_sort( left, mid );
		merge_sort( mid, right );
	}
	int *fa, *fb;
	fa = ff[t]; fb = ff[1-t];
	int p, q, zi;
	zi = left; p = left; q = mid;
	while( p<mid&&q<right ) {
		if( fa[p]>fa[q] ) {
			fb[zi++] = fa[q++];
			total += (mid-p);
		}else fb[zi++] = fa[p++];
	}
	while( p<mid ) fb[zi++] = fa[p++];
	while( q<right ) fb[zi++] = fa[q++];
	return 1-t;
}

int main() {
	while( (amount=get_int()) ) {
		for( int i=0; i<amount; ++i )
			ff[0][i] = get_int();
		total = 0;
		merge_sort( 0, amount );
		printf( "%I64d\n", total );
	}
}
