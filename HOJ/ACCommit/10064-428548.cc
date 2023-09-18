#include <cstdio>

__int64 pwm( __int64 base, __int64 exp, __int64 mod ) {
    __int64 ret=1;
    while( exp ) {
        if( exp&1LL )
            ret = ret*base%mod;
        base = base*base%mod;
        exp >>= 1;
    }
    return ret;
}

const int MOD = 10000000;
int bs, idx, kk;
__int64 mod;
char str[20];
int main() {
    while( scanf( "%d%d%d", &bs, &idx, &kk ), bs ) {
        mod = 1;
        for( int i=0; i<kk; ++i ) mod*=10;
        __int64 ret = bs, tmp;
        while( --idx ) {
            tmp = ret;
            ret = pwm( bs, ret, MOD );
            if( tmp==ret || ret%mod==0 )
                break;
        }
        ret %= mod;
        sprintf( str, "%%0%dI64d\n", kk );
        printf( str, ret );
    }
}
