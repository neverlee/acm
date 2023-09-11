#include<cstdio>
int main() {
	int hv[26]={0};
	for( int i; (i=getchar()-'a')>=0; ) ++hv[i];
	int ma=0, mi=100;
	for( int i=0; i<26; ++i ) {
		ma=ma>hv[i]?ma:hv[i];
		if( hv[i] && hv[i]<mi ) mi=hv[i];
	}
	ma-=mi; mi=ma;
	if( ma<2 ) ma=-1;
	for( int i=2; i<ma/2; ++i )
		if( ma%i==0 ) ma=-1;
	if( ma==-1 ) puts( "No Answer\n0" );
	else printf( "Lucky Word\n%d", mi );
}
