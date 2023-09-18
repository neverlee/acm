#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[1010][22], pos[1010];
int amount=0, ps[1010];
bool cmp( const int &a, const int &b ) {
    return strcmp( str[a], str[b] )<0;
}
void IMax( char &a, char b ) { if(a<b)a=b; }
int main() {
    for(; EOF != scanf( "%s", str[amount] ); amount++ )
        ps[amount]=amount;
    sort( ps, ps+amount, cmp );
    for( int i=1; i<amount; ++i ) {
        int p;
        char *st=str[ps[i-1]], *ed=str[ps[i]];
        for( p=0; st[p]&&ed[p]&&st[p]==ed[p]; ++p );
        IMax( pos[ps[i-1]], p );
        IMax( pos[ps[i]], p );
    }
    for( int i=0; i<amount; ++i ) {
        printf( "%s ", str[i] );
        str[i][pos[i]+1]=0;
        printf( "%s\n", str[i] );
    }
}
