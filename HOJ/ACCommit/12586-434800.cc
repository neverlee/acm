#include <iostream>
using namespace std;
long long x,y,q;

void exEuclid(long long a,long long b) {
    if (b==0) { x=1; y=0; q=a; }
    else {
        exEuclid(b,a%b);
        long long temp=x;
        x=y;
        y=temp-y*(a/b);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        long long n,m;
        scanf("%I64d%I64d",&n,&m);
        exEuclid(m,n);
        if(q!=1) printf("IMPOSSIBLE\n");
        else {
            while( x<0 ) x+=n;
            printf("%I64d\n",x%n);
        }
    }
    return 0;
}