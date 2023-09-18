//10389-数列.cpp
#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 50000;
struct Num{
	int data, left, right;
};
struct PNum{
	Num *p;
	Num *operator->() { return p; };
};
Num num[SIZE];
PNum p[2][SIZE];
int amount;
void init() {
	scanf( "%d", &amount );
	for( int i=0; i<amount; ++i ) {
		scanf( "%d", &num[i].data );
		num[i].left = 0;
		num[i].right = 0;
		p[0][i].p = num+i;
	}
}

void merge_sort() {
	PNum *fa, *fb;
	fa = p[0]; fb = p[1];
	for( int k=1; k<amount; k<<=1 ) {
		int dk = k*2;
		for( int i=0; i<amount; i+=dk ) {
			int p, pi, q, qi, z;
			int l, r;
			l = 0; r = 0;
			pi = (i+k)<amount?(i+k):amount;
			qi = (i+dk)<amount?(i+dk):amount;
			for( z=i, p=i, q=pi; p<pi&&q<qi; ) {
				if( fa[p]->data<fa[q]->data ) {
					++l;
					fa[p]->right+=r;
					fb[z++] = fa[p++];
				}else if( fa[p]->data>fa[q]->data ) {
					++r;
					fa[q]->left+=l;
					fb[z++] = fa[q++];
				}else {
					int a, b, n;
					a = b = 0;
					n = fa[p]->data;
					while( p<pi && fa[p]->data==n ) {
						++a;
						fa[p]->right+=r;
						fb[z++] = fa[p++];
					}
					while( q<qi && fa[q]->data==n ) {
						++b;
						fa[q]->left+=l;
						fb[z++] = fa[q++];
					}
					l+=a; r+=b;
				}
			}
			while( p<pi ) {
				fa[p]->right += r;
				fb[z++] = fa[p++];
			}
			while( q<qi ) {
				fa[q]->left += l;
				fb[z++] = fa[q++];
			}
		}
		swap( fa, fb );
	}
}

int main () {
	init();
	merge_sort();
	long long ret = 0;
	for( int i=0; i<amount; ++i )
		ret += (long long)num[i].left * num[i].right;
	printf( "%I64d", ret );
}

