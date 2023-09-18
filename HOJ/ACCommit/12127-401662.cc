#include<cstdio>
using namespace std;
__int64 n,m,r;
__int64 PMod() {
    __int64 ans=1, tmp=2;
    int k=n;
    while( k ) {
        if( k&(1L) ) ans=tmp*ans%m;
        tmp=tmp*tmp%m;
        k>>=1;
    }
    return ans;
}
int main() {
    int t; scanf( "%ld", &t );
    while( t-- ) {
        scanf( "%I64d %I64d", &n, &m );
        r=((n-4)*n+6)%m;
        r=r*PMod()%m;
        while(r<10)r+=m;
        r=(r-6)%m;
        printf( "%I64d\n", r );
    }
}
