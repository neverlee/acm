#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char name[10010][22], str[22];
int pn[10010];
int weight[10010], num;
bool Comp( const int a, const int b ) {
    return weight[a]>weight[b];
}
int main() {
    while( EOF != scanf( "%s", name[0] ) ) {
        int a;
        for( num=0; ; ++num ) {
            scanf( "%s", name[num] );
            if( strcmp( name[num], "END" )==0 ) break;
            scanf( "%d %d", &a, weight+num );
            weight[num]-=a;
            pn[num]=num;
        }
        sort( pn, pn+num, Comp );
        for( int i=0; i<num; ++i )
            puts( name[pn[i]] );
        putchar(\'\n\');
    }
}