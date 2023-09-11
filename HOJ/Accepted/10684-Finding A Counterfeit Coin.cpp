//10684-Finding A Counterfeit Coin.cpp
#include<cstdio>
#include<cstring>
char left[3][10], right[3][10], str[10], cmp[3];
char Check( char sw, char w ) {
	char d;
	for( int i=0; i<3; ++i ) {
		d=0;
		if( strchr( left[i], sw ) ) d+=1;
		if( strchr( right[i], sw ) ) d-=1;
		if( d*w!=cmp[i] ) return 0;
	}
	return 1;
}
int main(){
	int n; scanf( "%ld", &n );
	while( n-- ) {
		for( int i=0; i<3; ++i ) {
			scanf( "%s %s %s", left[i], right[i], str );
			if( str[0]=='u' ) cmp[i]=1;
			else if( str[0]=='d' ) cmp[i]=-1;
			else if( str[0]=='e' ) cmp[i]=0;
		}
		for( char i='A'; i<'M'; ++i ) {
			if( Check( i, -1 ) ) {
				printf( "%c is the counterfeit coin and it is light.\n", i );
				break;
			}
			if( Check( i, 1 ) ) {
				printf( "%c is the counterfeit coin and it is heavy.\n", i );
				break;
			}
		}
	}
}
