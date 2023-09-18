#include <cstdio>
#include <cstring>

const int SIZE = 1100;
char str[SIZE];
int len, del, ntxt;
void natual() {
    int i, j, zero;
    for( i=0, j=0; i<len; ++i )
        if( str[i]>=\'0\' )
            str[j++] = str[i];
    str[j] = 0;
    len = j;
}
void do_del() {
    int i, j, zero;
    while( del>0 ) {
        if( del>=len || (len==2&&str[1]==\'0\') ) {
            strcpy( str, "0" );
            break;
        }
        for( zero=0, i=1; i<len && str[i]==\'0\'; ++i ) ++zero;
        if( del>zero && str[0]>str[i] ) {
            for( j=0; j<i; ++j ) str[j]=0;
            del -= (zero+1);
        }else {
            for( i=1; i<len; ++i )
                if( str[i]>str[i+1] ) {
                    str[i]=0;
                    --del;
                    break;
                }
        }
        natual();
    }
}
int main() {
    scanf( "%d", &ntxt );
    while( ntxt-- ) {
        scanf( " %s %d", str, &del );
        len = strlen( str );
        do_del();
        puts( str );
    }
    return 0;
}