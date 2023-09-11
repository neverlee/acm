#include <cstdio>

const int SIZE = 100010;

int ay[SIZE], ni, sm;

void quick_sort( int st, int ed ) {
	int i, j, t;
	t = ay[st];
	i = st; j = ed-1;
	if( i>=j ) return;
	while( i<j ) {
		while( i<j && t<=ay[j] ) --j;
		ay[i] = ay[j];
		if( i<j ) ++sm;
		while( i<j && t>=ay[i] ) ++i;
		ay[j] = ay[i];
	}
	ay[i] = t;
	quick_sort( st, i );
	quick_sort( i+1, ed );
}

int main() {
	while( EOF != scanf( "%d", &ni ), ni ) {
		for( int i=0; i<ni; ++i )
			scanf( "%d", ay+i );
		sm = 0;
		quick_sort( 0, ni );
		printf( "%d\n", sm );
	}
}

