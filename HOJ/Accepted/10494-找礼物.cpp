//10494-找礼物.cpp
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

//typedef long long __int64;
const int SIZE = 100000;
struct Gift{
	char name[100];
	__int64 line;
}gift[SIZE];

struct PGift{
	Gift *p;
	Gift *operator->() { return p; }
	friend bool operator<( const PGift &pa, const PGift &pb ) {
		return (pa.p->line) < (pb.p->line);
	}
}pp[SIZE+1];

int ngift, nman;
int main() {
	scanf( "%d%d", &ngift, &nman );
	int x, y;
	double dist;
	for( int i=0; i<ngift; ++i ) {
		scanf( "%s%d%d", gift[i].name, &x, &y );
		dist = sqrt( (double)x*x+(double)y*y );
		gift[i].line = dist*10000;
		pp[i].p = gift+i;
	}
	sort( pp, pp+ngift );
	pp[ngift].p = gift;
	int t, e;
	for( t=0; nman>1&&t<ngift; --nman,++t )
		while( pp[t]->line == pp[t+1]->line && t<ngift ) ++t;
	if( t<ngift ) {
		for( e=t; e<ngift && pp[e]->line==pp[e+1]->line; ++e );
		//printf( "%ld %d\n", pp[t]->line/10000, e-t+1 );
		printf( "%I64d %d\n", pp[t]->line/10000, e-t+1 );
		for( ;t<=e ; ++t ) pp[t]->line=-1;
		for( int i=0; i<ngift; ++i )
			if( gift[i].line==-1 )
				puts( gift[i].name );
	}else puts( "555..." );
}

