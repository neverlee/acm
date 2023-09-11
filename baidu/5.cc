#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
	char str[110];
	scanf( "%s", str );
	bool hx, hu, bad;
	hx = hu = bad = 0;
	int len;
	len = strlen( str );
	for( int i=0; i<len; ++i ) {
		if( str[i]=='_' ) hx=1;
		if( isupper( str[i] ) ) hu=1;
		if( str[i]=='_' && str[i+1]=='_' ) bad=1;
	}
	if( (hx&&hu) || bad || !islower(str[0]) || !isalpha(str[len-1]) ) {
		puts( "Error!" );
		return 0;
	}
	if( hx==1 ) {
		for( int i=0; i<len; ) {
			if( islower( str[i] ) ) {
				putchar( str[i++] );
			}else if( str[i]=='_' ) {
				++i;
				putchar( str[i++]-32 );
			}
		}
	}else {
		for( int i=0; i<len; ) {
			if( islower( str[i] ) ) {
				putchar( str[i++] );
			}else if( isupper( str[i] ) ) {
				printf( "_%c", str[i++]+32 );
			}
		}
	}
	putchar('\n');
}
