#include <cstdio>
#include <cmath>

const __int64 INF = ((__int64)0x7FFFffff)*0x40000000;
__int64 nn, kk, ret;
__int64 fct, cnt;

void check() {
    __int64 ts=0, r;
    for( __int64 kn=nn; kn>0;  )
        ts += (kn/=fct);
    r = ts/cnt;
    ret = ret<r?ret:r;
}

void answer() {
    ret = INF;
    for( __int64 i=2; i<=(int)sqrt((double)kk)&&i<1000000; ++i ) {
        fct = i;
        cnt = 0;
        while( kk%i==0 ) {
            kk /= i;
            ++cnt;
        }
        if( cnt>0 ) check();
    }
    if( kk>1 ) {
        fct = kk;
        cnt = 1;
        check();
    }
    printf( "%I64d\n", ret );
}

int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        scanf( "%I64d%I64d", &nn, &kk );
        answer();
    }
}
