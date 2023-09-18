#include <cstdio>
const int lmt = 100000000;
int t,h,v,s;
int l,r,u,d;
int main() {
    scanf( "%d%d%d", &t, &h, &v );
    s = (t+h+v)/2;
    int low, high;
    low = -lmt; high = lmt;
    while( low<=high ) {
        r = (low+high)/2; u = s-r; l = r-h; d = u-v;
        if( u>lmt || l<-lmt || d>lmt) {
            low = r+1;
        }else if( u<-lmt || l>lmt || d<-lmt ) {
            high = r-1;
        }else break;
    }
    printf( "%d %d %d %d", l, r, u, d );
}