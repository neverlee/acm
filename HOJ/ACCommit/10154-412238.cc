#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned uint;
typedef unsigned long long ull;
const int BASE = 1000;
const int BASE_LEN = 3;
const uint P = 2013265921; //15*2^27+1
const uint OMEGA = 440564289; //root\xa3\xac31^15 % P
const uint INV_TWO = 1006632961; //2^(-1)
const int SIZE = 1048576;
char str[2][SIZE];
int ibit, ineed;
uint a[SIZE], b[SIZE], roots[SIZE];

uint Power(uint x, uint y) {
    uint res = 1;
    for (; y; y /= 2) {
        if (y&1) res = (ull)res*x%P;
        x = (ull)x*x%P;
    }
    return res;
}

void get_bit_length( int len ) {
    len = len/BASE_LEN + (len%BASE_LEN?1:0);
    for( ineed=1, ibit=0 ; ineed<len; ineed<<=1, ++ibit );
}

void convert( char *ss, int slen, uint *ary ) {
    memset( ary, 0, sizeof(int)*(ineed) );
    int id=0;
    for (int size = slen; size > 3; ss[size -= 3] = \'\0\')
        ary[id++] = atoi(ss+size-3);
    ary[id++] = atoi(ss);
}

void bit_reverse_copy( uint *tag, uint *src ) {
    for( int i=0; i<ineed; ++i ) {
        int k=0, m=i;
        for( int j=0; j<ibit; ++j, m>>=1 )
            k = (k<<1)+(m&1);
        tag[k] = src[i];
    }
}

void FFT(uint x[], int flag) {
    uint root; int n = ineed;
    if( flag ) root = Power(OMEGA, (1<<27)/n*(n-1));
    else root = Power(OMEGA, (1<<27)/n);
    roots[0] = 1;
    for (int i = 1; i < n; ++i)
        roots[i] = (ull)roots[i-1]*root%P;
    for (int k = 2; k <= n; k *= 2)
        for (int i = 0; i < n; i += k)
            for (int j = 0; j < k/2; ++j) {
                uint t = (ull)roots[n*j/k]*x[i+j+k/2]%P;
                x[i+j+k/2] = (x[i+j]-t+P)%P;
                x[i+j] = (x[i+j]+t)%P;
            };
}

int main() {
    while( EOF != scanf( "%s%s", str[0], str[1] ) ) {
        int il0, il1;
        il0 = strlen( str[0] );
        il1 = strlen( str[1] );
        get_bit_length( il0+il1 );
        convert( str[0], il0, roots );
        bit_reverse_copy( a, roots );
        FFT(a, 0);
        convert( str[1], il1, roots );
        bit_reverse_copy( b, roots );
        FFT(b, 0);
        for (int i = 0; i < ineed; ++i)
            b[i] = (ull)a[i]*b[i]%P;
        bit_reverse_copy( a, b );
        FFT(a, 1);
        
        uint inv_n = 1;
        for (int i = ineed; i /= 2; )
            inv_n = (ull)inv_n*INV_TWO%P;
        for (int i = 0; i < ineed; ++i)
            a[i] = (ull)a[i]*inv_n%P;

        for (int i = 1; i < ineed; ++i) {//\xbd\xf8\xce\xbb
            a[i] += a[i-1]/1000;
            a[i-1] %= 1000;
        }
        int iln;
        for( iln=ineed-1; iln>0&&a[iln]==0; --iln );
        printf("%u", a[iln]);//\xca\xe4\xb3\xf6
        for (--iln; iln >= 0; --iln)
            printf("%03u", a[iln]);
        putchar(\'\n\');
    }
    return 0;
}