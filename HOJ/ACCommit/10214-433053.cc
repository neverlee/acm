#include <cstdio>
#include <cctype>
#include <cstring>

int main() {
    char s[80], t[80];
    int k, l;
    while( scanf( "%d %s", &k, s ), k ) {
        l = strlen( s );
        for( int i=0; i<l; ++i ) {
            if( islower(s[i]) ) s[i] = s[i]-\'a\'+1;
            else if( s[i]==\'_\' ) s[i] = 0;
            else s[i] = 27;
        }
        for( int i=0; i<l; ++i ) {
            int d = k*i%l;
            int m = (s[i]+i)%28;
            if( m==0 ) t[d]=\'_\';
            else if( m<27 ) t[d]=m+(\'a\'-1);
            else t[d] = \'.\';
        }
        t[l]=0;
        puts(t);
    }
}
