#include <cstdio>
#include <cstring>

class Time{
public:
    int h, m ,t;
    void build() {
        scanf( "%d:%d", &h, &m );
        t = (h*60+m)%720;
    }
};

Time tt[3];
bool can[3];

bool cmp( Time &t, Time &t1, Time &t2 ) {
    int s, a, b;
    s = t.t;
    for( int i=0; i<=480; ++i ) {
        a = (720+s+i)%720;
        b = (720+s-i)%720;
        if( t1.t==a && t2.t==b || t1.t==b && t2.t==a )
            return 1;
    }
    return 0;
}

int main() {
    int T;
    scanf( "%d", &T );
    while( T-- ) {
        for( int i=0; i<3; ++i )
            tt[i].build();
        can[0] = cmp( tt[0], tt[1], tt[2] );
        can[1] = cmp( tt[1], tt[0], tt[2] );
        can[2] = cmp( tt[2], tt[0], tt[1] );
        int h=-1, cnt=0;
        for( int i=0; i<3; ++i )
        if( can[i] ) {
            ++cnt;
            h = i;
        }
        if( cnt!=1 ) puts( "Look at the sun" );
        else printf( "The correct time is %d:%02d\n", tt[h].h, tt[h].m );
    }
}
