//10033-奶牛浴场.cpp~'
#include <cstdio>
#include <algorithm>
using namespace std;
int leng, width;
int amount, ret;
struct Point{
	int x, y;
	void set( int ax, int ay ) { x=ax; y=ay; }
}src[5100];
bool cmpx( const Point &pa, const Point &pb ) { return pa.x<pb.x; }
bool cmpy( const Point &pa, const Point &pb ) { return pa.y<pb.y; }
int get_int() {
	int r; char c;
	while( (c=getchar())<'0' );
	r = c-'0';
	while( (c=getchar())>='0' ) r = r*10+c-'0';
	return r;
}

int bl, br, bs, bx, bc;
void search_x() {
	int dd;
	for( int i=1; i<amount; ++i ) {
		bl = src[i-1].x;
		bx = 0; bs = width;
		bc = src[i-1].y;
		for( int j=i; j<amount; ++j ) {
			br = src[j].x;
			dd = bs-bx;
			if( dd*(leng-bl) <= ret ) break;
			int tmp = dd*(br-bl);
			if( tmp>ret ) ret = tmp;
			if( src[j].y>bc ) {
				if( src[j].y<bs ) bs = src[j].y;
			}else {
				if( src[j].y>bx ) bx = src[j].y;
			}
		}
	}
}
void search_y() {
	int dd;
	for( int i=1; i<amount; ++i ) {
		bl = src[i-1].y;
		bx = 0; bs = leng;
		bc = src[i-1].x;
		for( int j=i; j<amount; ++j ) {
			br = src[j].y;
			dd = bs-bx;
			if( dd*(width-bl) <= ret ) break;
			int tmp = dd*(br-bl);
			if( tmp>ret ) ret = tmp;
			if( src[j].x>bc ) {
				if( src[j].x<bs ) bs = src[j].x;
			}else {
				if( src[j].x>bx ) bx = src[j].x;
			}
		}
	}
}
int main() {
	scanf( "%d%d%d", &leng, &width, &amount );
	amount += 4;
	src[0].set( 0, 0 );
	src[1].set( 0, width );
	src[2].set( leng, 0 );
	src[3].set( leng, width );
	for( int i=4; i<amount; ++i ) {
		src[i].x = get_int();
		src[i].y = get_int();
	}
	ret = 0;
	sort( src, src+amount, cmpx );
	search_x();
	sort( src, src+amount, cmpy );
	search_y();
	printf( "%d", ret );
}
