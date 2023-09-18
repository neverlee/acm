#include <cstdio>
#include <cstring>
#include <cctype>

char ss[100], sn[100];
int in[20];
bool crt;

void init() {
    int i, j;
    for( i=0, j=0; sn[i]; ++i ) {
        if( sn[i]==\'-\' ) continue;
        else if( isdigit(sn[i]) || sn[i]==\'X\'&&j==9 ) {
            if( sn[i]==\'X\' ) in[j] = 10;
            else in[j] = sn[i]-\'0\';
            ++j;
        }else {
            crt = 0;
            return;
        }
    }
    if( j!=10 ) {
        crt = 0;
        return;
    }
    for( int i=1; i<10; ++i )
        in[i] += in[i-1];
    for( int i=1; i<10; ++i )
        in[i] += in[i-1];
}

int main() {
    while( gets(ss)&&ss[0] ) {
        sscanf( ss, " %s", sn );
        crt = 1;
        init();
        if( in[9]%11!=0 ) {
            crt=0;
        }
        printf( "%s is ", sn );
        if( crt ) puts("correct.");
        else puts("incorrect.");
    }
}
