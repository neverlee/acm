#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int amount;
char slg[100];
int ilg[100];
const char ISF[6][10] = {"divine","evil","human","lying","day","night"};
const int CEND = 546;
bool have[5];
void output( int *on ) {
	int i;
	for( i=0; i<5; ++i )
	if( have[i] ) {
		if( on[i]==-1 )
			printf( "I don't know who %c is.\n", i+'A' );
		else printf( "%c is %s.\n", i+'A', ISF[on[i]] );
	}
	if( on[5]==-1 )
		puts( "I don't know it is day or night." );
	else printf( "It is %s.\n", ISF[on[5]+4] );
}
void test() {
	int k, i, t, rct;
	int on[6];
	vector<int> result;
	for( k=0; k<CEND; ++k ) {
		for( t=k, i=0; i<6; ++i, t/=3 )
			on[i] = t%3;
		bool flag=1;
		for( i=0; i<amount; ++i ) {
			rct = ilg[i];
			int s, n, w, b;
			s = (rct>>12)&0xf;
			n = (rct>>8)&0xf;
			w = (rct>>4)&0xf;
			b = rct&0xf;
			if( on[s]==1 || (on[s]==2&&on[5]==1) ) n = !n;
			if( b<3 && ((n==0)^(on[w]==b)) ) {
				flag=0; break;
			}
			if( b==3 && on[w]!=2 && (n^(on[w]==0)) ) {
				flag=0; break;
			}
			if( b==3 && on[w]==2 && !(on[5]^n) ) {
				flag=0; break;
			}
		}
		if( flag ) {
			for( t=0, i=5; i>=0; --i )
				t = (t<<2) + on[i];
			result.push_back( t );
		}
	}
	if( result.size()==0 ) {
		puts("This is impossible.");
	}else {
		for( t=result[0], i=0; i<6; ++i, t>>=2 )
			on[i] = t&0x3;
		for( k=1; k<result.size(); ++k ) {
			for( t=result[k], i=0; i<6; ++i, t>>=2 )
				if( on[i] != (t&0x3) )
					on[i] = -1;
		}
		output( on );
	}
}

int main() {
	int i, j;
	scanf( "%d%*c", &amount );
	memset( have, 0, sizeof(have) );
	for( i=0; i<amount; ++i ) {
		gets( slg );
		int ret=0, say = slg[0]-'A';
		have[say] = 1;
		ret |= (say<<12);
		if( slg[4]=='t' ) {
			ret |= (5<<4);
			if( slg[9]=='n' ) ret |= 1;
		}else {
			if( slg[3]=='I' ) ret |= (say<<4);
			else {
				ret |= ((slg[3]-'A')<<4);
				have[slg[3]-'A']=1;
			}
			int pi=8;
			if( slg[pi]=='n' ) {
				pi+=4;
				ret |= (1<<8);
			}
			for( j=0; j<4; ++j )
			if( slg[pi]==ISF[j][0] ) ret |= j;
		}
		ilg[i] = ret;
	}
	test();
}