#include <cstdio>
bool f[51][30000]={0};
int lmt, nn, dn, ni[100], sum, im;
int main() {
    scanf( "%d", &nn );
    dn = nn/2+nn%2;
    sum = 0;
    for( int i=0; i<nn; ++i ) {
        scanf( "%d", ni+i );
        sum += ni[i];
    }
    lmt = sum/2;
    f[0][0] = 1;
    for( int i=0; i<nn; ++i )
        for( int j=lmt; j>=ni[i]; --j )
            for( int k=dn; k>0; k-- )
                if( f[k-1][j-ni[i]]==1 ) f[k][j]=1;
    for( im=lmt; f[dn][im]==0; --im );
    if( nn%2 ) {
        --dn;
        for( int i=im; i<=lmt; ++i )
            if( f[dn][i]==1 ) im = i;
    }
    printf( "%d %d", im, sum-im );
}