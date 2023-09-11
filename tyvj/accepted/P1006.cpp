#include<cstdio>
int main() {
	char isbn[15];
	gets(isbn);
	int k=0;
	for( int i=0,j=0; i<11; ++i )
	if( isbn[i]>='0' )
		k+=((isbn[i]-'0')*(++j));
	k%=11;
	if( isbn[12]-'0'!=k && !(isbn[12]=='X'&&k==10) ) {
		isbn[12]=k+'0';
		if( k==10 ) isbn[12]='X';
		puts(isbn);
	}else puts( "Right" );
}
