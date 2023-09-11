#include <cstdio>
bool da[40];
int len, total;
bool isthree( int id, int ll ) {
	int i, j, k;
	id-=ll;
	for( i=id+ll, j=id, k=id-ll; i>id; --i, --j , --k )
		if( da[i]!=da[j] || da[i]!=da[k] )
			return 0;
	return 1;
}
void dg( int id ) {
	if( id==len ) {
		++total;
		return;
	}
	int i, k, flag;
	k=(id+1)/3;
	
	da[id]=0; flag=1;
	for( i=1; i<=k; ++i )
	if( isthree( id, i ) ) {
		flag=0;
		break;
	}
	if( flag ) dg( id+1 );
	
	da[id]=1; flag=1;
	for( i=1; i<=k; ++i )
	if( isthree( id, i ) ) {
		flag=0;
		break;
	}
	if( flag ) dg( id+1 );
}

int main() {
	scanf( "%d", &len );
	dg(0);
	printf( "%d", total );
	return 0;
}