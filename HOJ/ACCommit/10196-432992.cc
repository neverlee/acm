#include <cstdio>
#include <cstring>

int fib[50] = {1,2};

void init_fib() {
    for( int i=2; i<50; ++i )
        fib[i] = fib[i-1]+fib[i-2];
}

char a[50], b[50], c[50];
int ia, ib, ic;

int from( char *s ) {
    int l=strlen(s), k=0;
    for( int i=l-1, j=0; i>=0; --i, ++j )
        if( s[i]==\'1\' ) k+=fib[j];
    return k;
}

void get( int ii, char *ss ) {
    if( ii==0 ) {
        strcpy( ss, "0" );
        return;
    }
    int ll = 0;
    while( fib[ll]<=ii ) ++ll;
    int i, j;
    for( i=ll-1, j=0; i>=0; --i, ++j ) {
        if( ii>=fib[i] ) {
            ss[j] = \'1\';
            ii -= fib[i];
        }else ss[j] = \'0\';
    }
    ss[j]=0;
}

int main() {
    init_fib();
    while( ~scanf( "%s%s", a, b ) ) {
        ia = from(a); ib = from(b);
        ic = ia+ib;
        get( ia, a );
        get( ib, b );
        get( ic, c );
        int lc = strlen(c);
        char ss[20];
        sprintf( ss, "%%%ds\n", lc );
        printf("  ");
        printf( ss, a );
        printf("+ ");
        printf( ss, b );
        printf("  ");
        for( int i=0; i<lc; ++i ) putchar(\'-\');
        printf("\n  %s\n\n", c );
    }
}
