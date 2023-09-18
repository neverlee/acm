//10234-Forests.cpp
#include<cstdio>
char rs[110][110], s[20], use[110];
int p, t ,i , j, h;
char IsSame( int a, int b ) {
	int n;
	for( n=0; n<t; ++n )
	if( rs[a][n]!=rs[b][n] ) return 0;
	return 1;
}
int main(){
	scanf( "%ld %ld%*c", &p, &t );
	while( gets(s) ) {
		if( EOF!=sscanf( s, "%ld %ld", &i, &j ) );
			rs[i-1][j-1]=1;
	}
	h=p;
	for( i=0; i<p-1; ++i ) if( !use[i] )
	for( j=i+1; j<p; ++j )
	if( IsSame( i, j ) ){
		--h; use[j]=1;
	};
	printf( "%ld", h );
}
