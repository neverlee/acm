//12354-Shape Number.cpp
#include <cstdio>
#include <cstring>
const int SIZE = 300010;
char str[SIZE];
int len;
int lowest() {
	int i, j, count, x, y;
	i = 0; j = 1; count = 0;
	while( i<len && j<len && count <len ) {
		x = (i+count)%len;
		y = (j+count)%len;
		if( str[x]==str[y] ) ++count;
		else {
			if( str[x]>str[y] )
				i = x+1;
			else j = y+1;
			count = 0;
		}
		if( i==j ) ++j;
	}
	return i;
}

int main() {
	while( gets( str ) ) {
		len = strlen( str );
		str[len] = str[0];
		for( int j=0; j<len; ++j )
			str[j] = ( str[j+1]+8-str[j] ) % 8 + '0';
		str[len]=0;
		int st = lowest();
		printf( "%s", str+st );
		str[st] = 0;
		puts( str );
	}
}

