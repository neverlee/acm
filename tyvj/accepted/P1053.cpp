#include <cstdio>
#include <cstring>
#include <cctype>
char str[200];
int p1, p2, p3;
int main() {
	int i;
	scanf( "%d%d%d%s", &p1, &p2, &p3, &str );
	for( i=0; str[i]; ++i ) {
		if( str[i]=='-' && str[i-1]<str[i+1] &&
			( ( isdigit(str[i-1]) && isdigit(str[i+1]) )
			|| ( islower(str[i-1]) && islower(str[i+1]) ) )
		) {
			char co=str[i-1]+1;
			if( p1==2&&islower(str[i-1]) ) co-=32;
			if( p1==3 ) co='*';
			if( p3==2 && p1!=3 ) co += str[i+1]-str[i-1]-2;
			int j, k;
			for( j=str[i-1]+1; j<str[i+1]; ++j ) {
				for( k=0; k<p2; ++k )
					putchar( co );
				if( p1!=3 ) {
					if( p3==1 ) ++co;
					else --co;
				}
			}
		}else {
			putchar( str[i] );
		}
	}
	return 0;
}