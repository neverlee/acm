//11490-Simpsons' Hidden Talents.cpp
#include<cstdio>
#include<cstring>
char str1[100000], str2[100000];
int len1, len2 ,lm;
int Check() {
	int i, j;
	for( i=lm; i>0; --i ) {
		for( j=0; j<i; ++j )
			if( str1[j]!=str2[len2-i+j] ) break;
		if( j==i )return j;
	}
	return 0;
}
int main() {
	while( EOF != scanf( "%s%s", str1, str2 ) ) {
		len1=strlen( str1 );
		len2=strlen( str2 );
		lm = len1<len2?len1:len2;
		lm = Check();
		str1[lm]=0;
		if( lm ) printf( "%s %ld\n", str1, lm );
		else puts( "0" );
	}
}
