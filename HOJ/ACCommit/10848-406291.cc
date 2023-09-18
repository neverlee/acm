#include <stdio.h>
const unsigned Mod = 34943;
int main() {
    char str[1200];
    while( gets(str), !(str[0]==\'#\'&&str[1]==0) ) {
        unsigned div=0;
        for( int i=0; str[i]; ++i ) {
            div<<=8;
            div+=str[i];
            div%=Mod;
        }
        div<<=16;
        for( int i=0; i<34943; ++i )
        if( (div+i)%Mod==0 ) {
            printf( "%02X %02X\n", i>>8, i&255 );
            break;
        }
    }
}
