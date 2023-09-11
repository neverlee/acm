//11119-Maze Escape.cpp
#include<cstdio>
int n, m, a, t, s;
double r;
int main() {
	while( scanf( "%ld%ld", &n, &m ), n ) {
		s=0;
		for( int i=0; i<n; ++i ) {
			scanf( "%ld", &t );
			if( i+1!=m ) s+=t;
			else a=t;
		}
		if( n>1 ) r=s/2.0+a;
		else r=t;
		printf( "%.2lf\n", r );
	}
}
