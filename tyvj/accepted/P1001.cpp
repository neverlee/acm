#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int iaNum[10000], iTh, iAmount;

bool IsPrime( int num ) {
	if( num==2 )return 1;
	if( num<2 || num%2==0 ) return 0;
	int ie=(int)sqrt( (double)num );
	for( int i=3; i<=ie; i+=2 )
	if( num%i==0 ) return 0;
	return 1;
}
int main() {
	scanf( "%d%d", &iAmount, &iTh );
	for( int i=0; i<iAmount; ++i ) scanf( "%d", iaNum+i );
	sort( iaNum, iaNum+iAmount );
	int iK = iaNum[ iAmount-iTh ] - iaNum[ iTh-1 ];
	if( IsPrime( iK ) ) puts( "YES" );
	else puts( "NO" );
	printf( "%d\n", iK );
}
