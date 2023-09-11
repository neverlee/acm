//10409-旅行计划.cpp
#include <cstdio>
#include <algorithm>
using namespace std;
const int CAN = 800;
const int MAXX = 0x7fffffff;
const int SIZE = 1010;
int length, amount;
struct Hotel{
	int away, price;
	friend bool operator<( const Hotel &ha, const Hotel &hb ) {
		return ha.away<hb.away;
	}
} hotel[SIZE];
int fl[SIZE], fp[SIZE], pre[SIZE];
void output() {
	int ret[SIZE], a, n;
	for( a=amount, n=0; pre[a]; a=pre[a], n++ )
		ret[n] = hotel[pre[a]].away;
	for( int i=n-1; i>0; --i ) printf( "%d ", ret[i] );
	printf( "%d\n", ret[0] );
}
void dp_price() {
	fl[0] = fp[0] = 0;
	for( int i=1; i<=amount; ++i ) {
		fp[i] = MAXX;
		for( int j=i-1; j>=0 && hotel[i].away-hotel[j].away<=CAN ; --j ) {
			int tmp;
			tmp = fp[j]+hotel[i].price;
			if( tmp<=fp[i] ) {
				if( tmp<fp[i] || fl[j]+1<fl[i] ) {
					pre[i] = j;
					fl[i] = fl[j]+1;
				}
				fp[i] = tmp;
			}
		}
	}
	output();
}
void dp_day() {
	fl[0] = fp[0] = 0;
	for( int i=1; i<=amount; ++i ) {
		fl[i] = MAXX;
		for( int j=i-1; j>=0 && hotel[i].away-hotel[j].away<=CAN ; --j ) {
			int tmp, k;
			tmp = fp[j]+hotel[i].price;
			k = fl[j]+1;
			if( k<=fl[i] ) {
				if( tmp<fp[i] || k<fl[i] ) {
					pre[i] = j;
					fp[i] = tmp;
				}
				fl[i] = k;
			}
		}
	}
	output();
}
int main() {
	scanf( "%d%d", &length, &amount );
	for( int i=1; i<=amount; ++i )
		scanf( "%d%d", &hotel[i].away, &hotel[i].price );
	sort( hotel+1, hotel+1+amount );
	++amount;
	hotel[amount].away = length;
	hotel[amount].price = 0;
	dp_price();
	dp_day();
}