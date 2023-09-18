#include <cstdio>
#include <vector>
using namespace std;

int p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
vector<int> vi, cnt;
const int lmt = 2000000000;
__int64 ll=1;
int hv=1;

void dg( int lv, int ceil ) {
    __int64 dl=1;
    for( int i=1; i<=ceil; ++i ) {
        dl *= p[lv];
        ll*=dl;
        if( ll>lmt ) {
            ll/=dl;
            break;
        }
        hv*=(i+1);
        vi.push_back( ll );
        cnt.push_back( hv );
        dg( lv+1, i );
        ll/=dl;
        hv/=(i+1);
    }
}

int main() {
    long long ll=1;
    dg( 0, 32 );
    vi.push_back( 1 );
    cnt.push_back( 0 );
    int n, ret=0, k=-1;
    scanf( "%d", &n );
    for( int i=0; i<vi.size(); ++i )
        if( (cnt[i]>k || cnt[i]==k&&vi[i]<ret) && vi[i]<=n ) {
            ret = vi[i];
            k = cnt[i];
        }
    printf( "%d", ret );
}
