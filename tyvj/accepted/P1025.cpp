#include<cstdio>
#include<cstring>
int main() {
	int n;
	char str[100];
	scanf( "%d", &n );
	while( n-- ) {
		scanf( "%s", str );
		if( !(str[strlen(str)-1] & 1) ) puts("even");
		else puts("odd");
	}
}

