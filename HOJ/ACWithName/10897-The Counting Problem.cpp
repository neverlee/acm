//10897-The Counting Problem.cpp
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int hn[10][2]={1,1};
void Init(){
	for( int i=1,k=10; i<9; ++i,k*=10 ){
		hn[i][0] = hn[i-1][0]+9*hn[i-1][1];
		hn[i][1] = k*(i+1);
	}
}
struct Count{
	int n, h[10];
	Count(int nm){
		n=nm;
		int k,w,d;
		for( w=1,k=10; k<n ; ++w,k*=10 );
		if( k!=n ) {
			--w;
			k/=10;
		}
		memset( h, 0, sizeof(h) );
		h[0] = hn[w][0]-hn[w][1];
		for( ; w>0 ; --w,k/=10 ) {
			d= nm/k%10;
			for( int i=0; i<d; ++i ) h[i] += k;
			for( int i=0; i<10; ++i ) h[i] += d*hn[w-1][1];
			h[d] += nm%k+1;
		}
		d = nm%10;
		for( int i=0; i<=d; ++i) ++h[i];
	}
	void Output(){
		for( int i=0; i<9; ++i ) printf( "%ld ", h[i] );
		printf( "%ld\n", h[9] );
	}
};
int main(){
	int s,e;
	Init();
	while( scanf( "%ld%ld", &s, &e ), s||e ) {
		if( s>e )swap( s, e );
		Count cs(s), ce(e);
		for( int i=0; i<10; ++i )
			ce.h[i] -= cs.h[i];
		do{
			e=s%10;
			++ce.h[e];
			s/=10;
		}while( s );
		ce.Output();
	}
}
