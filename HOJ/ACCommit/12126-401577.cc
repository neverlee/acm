#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define Sqare(x) ((x)*(x))
struct Point {
    short x,y;
    double Distance(Point &p) {
        return sqrt( Sqare(x-p.x) + Sqare(y-p.y) );
    }
};
struct Line {
    short from, to;
    double length;
};
Point cab[1010];
Line tree[1010];
int amount;
bool Prim( int si ) {
    int m,v;
    double min, max=20000.0, d;
    v=si;
    for( int i=0; i<amount-1; ++i ) {
        tree[i].from=v;
        if( i>=v ) {
            tree[i].to=i+1;
            tree[i].length=cab[v].Distance( cab[i+1] );
        }else {
            tree[i].to=i;
            tree[i].length=cab[v].Distance( cab[i] );
        }
    }

    for( int i=0; i<amount-1; ++i ) {
        min=max;
        for( int j=i; j<amount-1; ++j )
        if( tree[j].length<min ) {
            min=tree[j].length;
            m=j;
        }
        swap( tree[m], tree[i] );
        v=tree[i].to;
        for( int j=i+1; j<amount-1; ++j ) {
            d=cab[v].Distance( cab[tree[j].to] );
            if( d<tree[j].length ) {
                tree[j].length=d;
                tree[j].from=v;
            }
        }
    }
    d=0;
    for( int i=0; i<amount-1; ++i )
        d+=tree[i].length;
    printf("%.2lf\n",d);
}
int main() {
    while( scanf( "%ld", &amount ), amount ) {
        for( int i=0; i<amount; ++i )
            scanf( "%d %d", &cab[i].x, &cab[i].y );
        Prim(0);
    }
}
