#include<cstdio>
int f[1001];
int sent, man;

void init() {
	scanf( "%d%d", &sent, &man );
	for( int i=0; i<=man; ++i ) f[i]=i;
}

int find( int n ) {
	if( f[n]!=n )
		return find( f[n] );
	else return n;
}

void work() {
	int ia, ib, rm=0;
	while( sent-- ) {
		scanf( "%d%d", &ia, &ib );
		if( (ia=find( ia )) == (ib=find( ib )) )
			++rm;
		else f[ib]=ia;
	}
	printf( "%d", rm );
}

int main() {
	init();
	work();
}
