#include<cstdio>
#include<algorithm>
using namespace std;
const int SIZE = 100010;
class Input {
private:
    char ic;
    int ii;
public:
    int Int() {
        while( (ic=getchar()) < \'0\' );
        ii = ic-\'0\';
        while( (ic=getchar()) >= \'0\' )
            ii = ii*10+ic-\'0\';
        return ii;
    }
};
Input wget;
int amount, opt;
class Para {
private:
    int data[SIZE], have[SIZE];
public:
    void Init() {
        for( int i=0; i<amount; ++i ) {
            data[i]=i;
            have[i]=1;
        }
    }
    int Parent( int first ) {
        if( data[first] == first ) return first;
        else return ( data[first] = Parent( data[first] ) );
    }
    void Merge( int one, int two ) {
        one = Parent( one );
        two = Parent( two );
        if( one == two ) return;
        data[two] = one;
        have[one] += have[two];
    }
    void Work() {
        int a, b;
        while( opt-- ) {
            a = wget.Int()-1; b = wget.Int()-1;
            Merge( a, b );
        }
        int cnt = 0;
        for( int i=0; i<amount; ++i )
        if( data[i]==i ) {
            data[cnt] = have[i];
            ++cnt;
        }
        printf( "%d", cnt );
        sort( data, data+cnt );
        for( int i=0; i<cnt; ++i )
            printf( " %d", data[i] );
        putchar( \'\n\' );
    }
};
Para apara;
int main() {
    while( 1 ) {
        amount = wget.Int();
        opt = wget.Int();
        if( amount==0 ) break;
        apara.Init();
        apara.Work();
    }
}
