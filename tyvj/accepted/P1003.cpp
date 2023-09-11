#include<cstdio>
int main() {
	int m,t,u,f,d;
	scanf( "%d %d %d %d %d", &m, &t, &u, &f, &d );
	f*=2;u+=d;d=0;
	char c;
	while( EOF!=(c=getchar()) )
	if( c>='a' ){
		if( c=='f' ) m-=f;
		else m-=u;
		if( m<0 ) {
			printf( "%d", d );
			return 0;
		}else ++d;
	}
	printf( "%d", d );
}
