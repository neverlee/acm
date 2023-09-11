#include<cstdio>
int main() {
	int can, num; bool f[20010]={0};
	scanf( "%d%d", &can, &num );
	f[0]=1;
	while( num-- ) {
		int thi; scanf( "%d", &thi );
		for( int i=can-thi; i>=0; --i )
			if( f[i] ) f[i+thi]=1;
	}
	for( int i=can; i>=0; --i )
		if( f[i] ) {
			printf( "%d", can-i );
			return 0;
		}
}
