//10181-和集.cpp
#include<cstdio>
#include<algorithm>
using namespace std;
struct Sum{
	int ad;
	short x,y;
};
int num[1000], many, amount;
Sum sum[550000];
bool Compare(const Sum &s1, const Sum &s2) {
	return s1.ad < s2.ad;
}
int main(){
	while( scanf("%ld",&many), many ) {
		for( int i=0; i<many; ++i) scanf("%ld", num+i);
		sort( num, num+many );

		amount=0;
		for( int i=1; i<many; ++i )
			for( int j=i; j<many; ++j ) {
				sum[amount].ad = num[i-1]+num[j];
				sum[amount].x = i-1;
				sum[amount].y = j;
				++amount;
			}
		sort( sum, sum+amount, Compare );
		Sum tmp, *p;
		for( int i=many-1; i>0; --i )
			for( int j=0; j<i; ++j ){
				tmp.ad = num[i]-num[j];
				tmp.x = j;
				tmp.y = i;
				p = lower_bound( sum, sum+amount, tmp, Compare );
				if( p<sum ) continue;
				for( ; p->ad==tmp.ad && p<sum+amount; ++p ){
					if( p->x != tmp.x
							&& p->y != tmp.y
							&& p->x != tmp.y
							&& p->y != tmp.x ) {
						printf( "%ld\n", num[i] );
						goto SFind;
					}
				}
			}
		puts("no solution");
SFind:;
	}
}
