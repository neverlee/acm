#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int num, prime;
double last;
class Fraction{
	int mother, son;
public:
	Fraction() {}
	Fraction( int s, int m ) {
		mother = m;
		son = s;
	}
	double getDouble() {
		return son/(double)mother;
	}
	void normal() {
		int m=mother, s=son;
		while( s!=0 ) {
			m%=s;
			swap( m, s );
		}
		mother/=m;
		son/=m;
	}
	void output() {
		printf( "%d/%d", son, mother );
	}
};

int find( int ip ) {
	int low, high, mid;
	low=1; high=num;
	while( low<high ) {
		mid = (low+high)/2;
		if( mid*mid>ip ) high = mid;
		else low = mid+1;
	}
	return high;
}
int main() {
	int i;
	scanf( "%d%d", &prime, &num );
	last = sqrt(prime);
	Fraction left(1,1), right(num,1);
	for( i=num; i>0; i-- ) {
		int ip=i*i/prime;
		int mm = find(ip);
		Fraction fl(i, mm), fr(i,mm-1);
		if( fl.getDouble()>left.getDouble() && fl.getDouble()<last )
			left = fl;
		if( fr.getDouble()<right.getDouble() && fr.getDouble()>last)
			right = fr;
	}
	left.normal();
	left.output();
	putchar(' ');
	right.normal();
	right.output();
	return 0;
}









