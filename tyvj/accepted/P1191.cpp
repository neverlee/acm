#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int group, amount;
int high[5010];

void init() {
	scanf( "%d%d", &group, &amount );
	for( int i=0; i<amount; ++i )
		scanf( "%d", high+i );
	for( int i=1; i<amount; ++i )
		high[i-1] = (high[i]-high[i-1])*(high[i]-high[i-1]);
}

int f[2][5010], *fa, *fb;
const int INTF = 0x0fFfFfFf;

int imin( int a, int b ) { return a<b?a:b; }

void dp() {
	fa=f[0]; fb=f[1];
	fa[amount-1]=fa[amount-2]=INTF;
	for( int i=amount-3; i>=0; --i ) 
		fa[i] = imin( fa[i+1], high[i] );
	for( int i=2; i<=group; ++i ) {
		for( int j=amount-1; j>=0; --j ) {
			fb[j] = INTF;
			if( j<=amount-3*i ) {
				fb[j] = imin( fb[j+1], fa[j+2]+high[j] );
			}
		}
		swap( fa, fb );
	}
	printf( "%d", fa[0] );
}

int main() {
	init();
	dp();
}


