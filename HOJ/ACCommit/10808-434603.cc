#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1000010; //

struct Node{
    int x, y;
    bool operator<( const Node &b ) const {
        return x<b.x || x==b.x&&y<b.y;
    }
};

int amount;
Node ele[N];

int getint() {
    char c; int k;
    while( (c=getchar())<\'0\' );
    k = c-\'0\';
    while( (c=getchar())>=\'0\' )
        k = k*10+c-\'0\';
    return k;
}

int st[N], ph;
void work() {
    ph = 0;
    st[0] = ele[0].y;
    int low, high, mid, t;
    for( int i=1; i<amount; ++i ) {
        t = ele[i].y;
        if( st[ph]>t ) {
            st[++ph] = t;
        }else {
            low = 0; high = ph;
            while( low<high ) {
                mid = (low+high)/2;
                if( st[mid]>t )
                    low = mid+1;
                else high = mid;
            }
            st[low] = ele[i].y;
        }
    }
    printf( "%d\n", ph+1 );
}

int main() {
    while( ~scanf( "%d", &amount ) ) {
        for( int i=0; i<amount; ++i ) {
            ele[i].x = getint();
            ele[i].y = getint();
        }
        sort( ele, ele+amount );
        work();
    }
}
