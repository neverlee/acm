#include<cstdio>
int  np[20001] = { 0, 1 };
void initprime() {
	for( int i=2; i<20000; i++ ) {
		if( np[i]==0 )
		for( int j=i+i; j<=20000; j+=i )
			np[j]=i;
	}
}
int pm( int k ) {
	return np[k]?np[k]:k;
}
int main() {
	int a, m, n;
	initprime();
	scanf( "%d", &n );
	m=1;
	while( n-- ) {
		scanf( "%d", &a );
		m=pm(m)<pm(a)?a:m;
	}
	printf( "%d", m );
}
