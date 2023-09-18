#include<cstdio>
#include<algorithm>
using namespace std;
double ar[25], sum;
int num;
bool flag;
int main() {
    while( scanf( "%d", &num ), num ) {
        for( int i=0; i<num; ++i )
            scanf( "%lf", ar+i );
        sort( ar, ar+num );
        sum=0;
        flag=0;
        for( int i=0; i<num-1&&!flag; ++i ) {
            sum+=ar[i];
            for( int j=i+1; j<num&&!flag; ++j )
                if( ar[j]<=sum ) flag=1;
        }
        if( flag ) puts( "YES" );
        else puts( "NO" );
    }
}