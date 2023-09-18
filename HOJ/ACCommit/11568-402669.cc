#include<cstdio>
char Get() {
    char d;
    while( (d=getchar()) <= \' \' );
    return d;
}
int main() {
    __int64 t, a, last;
    char s;
    scanf( "%I64d", &t );
    while(t--) {
        scanf( "%I64d", &last );
        while( s=Get(), s != \'=\' ) {
            scanf( "%I64d", &a );
            if( s==\'+\' ) last+=a;
            else if( s==\'-\' ) last-=a;
            else if( s==\'*\' ) last*=a;
            else if( s==\'/\'&&a ) last/=a;
        }
        printf( "%I64d\n", last );
    }
}
