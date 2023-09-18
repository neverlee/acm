#include<cstdio>
#include<cstring>
class GetInt {
private:
    char c;
    int in;
public:
    int NextInt() {
        while( (c=getchar())<\'0\' );
        in = c-\'0\';
        while( (c=getchar())>=\'0\' ) in = in*10+c-\'0\';
        return in;
    }
};
GetInt wget;
int base[20], have[20], amount, tmp;
int main() {
    base[0]=1;
    for( int i=1; i<20; ++i ) base[i]=base[i-1]<<1;
    while( EOF != scanf( "%d", &amount ) ) {
        if( amount==1 ) {
            printf( "%d\n", wget.NextInt() );
            continue;
        }
        memset( have, 0, sizeof(have) );
        for( int i=0; i<amount; ++i ) {
            tmp=wget.NextInt();
            for( int j=0; j<20; ++j )
                if( (tmp&base[j])>0 ) ++have[j];
        }
        __int64 sum=0;
        for( int i=0; i<20; ++i )
            sum += (__int64)base[i]*(amount-have[i])*have[i];
        printf( "%I64d\n", sum<<1 );
    }
}
