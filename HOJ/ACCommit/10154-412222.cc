#include <cstdio>
#include <complex>
#include <cmath>
using namespace std;

typedef complex<double> cpx;

const double PI = 3.1415926535897932384626;
const int BASE = 10000;
const int BASE_LEN = 4;

const int DLEN = 1000;
const int SIZE = 2197;

char snum[2][DLEN]; int ils[2], ineed, ibit;
int inum[SIZE/2];
cpx fxx[2][SIZE/2];
__int64 ret[SIZE/2];
void get_bit_length( int len ) {
    len = len/BASE_LEN + (len%BASE_LEN?1:0);
    for( ineed=1, ibit=0 ; ineed<len; ineed<<=1, ++ibit );
}

void convert( char *ss, int slen, int *ary ) {
    static int base[4] = {1, 10, 100, 1000};
    memset( ary, 0, sizeof(int)*(ineed) );
    for( int i=slen-1, j=0; i>=0; --i, ++j )
        ary[j>>2] += (ss[i]-\'0\')*base[j&3];
}

template<class T>
void bit_reverse_copy( cpx *xx, T *ty ) {
    for( int i=0; i<ineed; ++i ) {
        int k=0, m=i;
        for( int j=0; j<ibit; ++j, m>>=1 )
            k = (k<<1)+(m&1);
        xx[k] = ty[i];
    }
}

void FFT( cpx *xx, int flag ) {
    double dvPI;
    dvPI = flag?-PI:PI;
    for( int k=1; k<ineed; k<<=1 ) {
        cpx wb( cos(dvPI/k), sin(dvPI/k) );
        for( int d=0; d<ineed; d+=2*k ) {
            int ie = d+k;
            cpx wn = 1;
            for( int i=d, j=d+k; i<ie; ++i, ++j ) {
                cpx tx1, tx2, mx;
                mx = wn*xx[j];
                tx1 = xx[i]+mx;
                tx2 = xx[i]-mx;
                xx[i] = tx1; xx[j] = tx2;
                wn *=wb;
            }
        }
    }
}

int main() {
    while( EOF != scanf( "%s%s", snum[0], snum[1] ) ) {
        ils[0] = strlen( snum[0] );
        ils[1] = strlen( snum[1] );
        get_bit_length( ils[0]+ils[1] );
        convert( snum[0], ils[0], inum );
        bit_reverse_copy( fxx[0], inum );
        FFT( fxx[0], 0 );
        convert( snum[1], ils[1], inum );
        bit_reverse_copy( fxx[1], inum );
        FFT( fxx[1], 0 );
        for( int i=0; i<ineed; ++i )
            fxx[1][i]*=fxx[0][i];
        bit_reverse_copy( fxx[0], fxx[1] );
        FFT( fxx[0], 1 );
        for( int i=0; i<ineed; ++i )
            ret[i] = fxx[0][i].real()/ineed+0.5;
        for( int i=1; i<ineed; ++i ) {
            ret[i] += ret[i-1]/BASE;
            ret[i-1] %= BASE;
        }
        int nl;
        for( nl=ineed-1; nl>0&&ret[nl]==0; --nl );
        printf( "%I64d", ret[nl] );
        for( --nl; nl>=0; --nl )
            printf( "%04I64d", ret[nl] );
        printf("\n");
    }
}