#include<cstdio>
char str[1010];
int sa, l, sb;
int IMin( int a, int b ) { return a<b?a:b; }
int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        scanf( "%s", str );
        sa=0;
        for( l=0; str[l]; ++l ) {
            str[l]-=\'A\';
            sa+= IMin( str[l], 26-str[l] );
        }
        if( l<2 ) {
            printf( "%d\n", sa );
            continue;
        }
        sb=sa+l-1;

        for( int i=0, len; i<l; i=i+len)
        if( str[i]==0 ) {
            len=1;
            for( ; str[i+len]==0&&i+len<l; ++len );
            int left=i, right=l-i-len;
            if( i==0 ) {
                sb=IMin( sa+right, sb );
                continue;
            }
            if( i+len==l ) {
                sb=IMin( sa+left-1, sb );
                continue;
            }
            sb=IMin( sa+(left-1)*2+right, sb );
            sb=IMin( sa+left+2*right-1, sb );
        }else len=1;
        printf( "%d\n", sb );
    }
}
