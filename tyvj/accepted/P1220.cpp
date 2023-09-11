#include <cstdio>
int n, m, p, a;
int i, x, y;
int st[200001];
int find( int id ) {
	if( st[id]==id ) return id;
	else return st[id] = find( st[id] );
}
void goon( int x, int y ) {
	y += n;
	st[ find(x) ] = find(y);
}
int main() {
	scanf( "%d%d%d", &n, &m, &p );
	a = n+m;
	for( i=0; i<=a; ++i ) st[i]=i;
	while( p-- ) {
		scanf( "%d%d", &x, &y );
		goon( x, y );
	}
	int r=0;
	for( i=1; i<=n; ++i )
	if( st[i]>n && find(st[i])!=0 ){
		++r;
		st[ find( st[i] ) ] = 0;
	}
	printf( "%d", r-1 );
}