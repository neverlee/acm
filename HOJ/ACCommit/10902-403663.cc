#include<cstdio>
#include<algorithm>
using namespace std;
int ih, king[1010], tian[1010];
int GetAns() {
    int kl,kr,tl,tr, last=0;
    kl=tl=0;
    kr=tr=ih-1;
    for( int i=0; i<ih; ++i ) {
        if( tian[tr]>king[kr] ) {
            last+=200;
            --tr; --kr;
        }else if( tian[tr]<king[kr] ) {
            last-=200;
            ++tl; --kr;
        }else if( tian[tl]>king[kl] ) {
            last+=200;
            ++tl; ++kl;
        }else if( tian[tl]<king[kl] ) {
            last-=200;
            ++tl; --kr;
        }else {
            if( tian[tl]<king[kr] )
                last-=200;
            ++tl; --kr;
        }
    }
    return last;
}
int main() {
    while( scanf( "%ld", &ih ), ih ) {
        for( int i=0; i<ih; ++i )
            scanf( "%ld", tian+i );
        sort( tian, tian+ih );
        for( int i=0; i<ih; ++i )
            scanf( "%ld", king+i );
        sort( king, king+ih );
        printf( "%ld\n", GetAns() );
    }
}
