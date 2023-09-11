//12365-Death Knight Hero.cpp
#include <cstdio>

char str[1010];

int main() {
	int n, s; gets( str );
	sscanf( str, "%d", &n );
	s = 0;
	while( n-- ) {
		gets( str );
		int f=1;
		for( int i=0; str[i]&&str[i+1]; ++i )
			if( str[i]=='C' && str[i+1]=='D' ) {
				f=0; break;
			}
		s+=f;
	}
	printf( "%d", s );
}
