#include<cstdio>
int nm[10]={6,2,5,5,4,5,6,3,7,6};
int Get( int num ) {
	int have=0;
	do{
		int k=num%10;
		have+=nm[k];
		num/=10;
	}while( num );
	return have;
}
int main() {
	int n, s=0; scanf( "%d", &n ); n-=4;
	for( int i=0; i<2000; ++i )
		for( int j=0; j<2000; ++j )
			if( Get(i)+Get(j)+Get(i+j)==n ) {
				++s;
			}
	printf( "%d", s );
}

