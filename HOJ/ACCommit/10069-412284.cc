#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int SIZE = 150000;
int star_amount;
struct Star{
    int x, y;
    int below;
}stars[SIZE];
struct PStar{
    Star *ps;
    Star *operator->() { return ps; }
}pt[2][SIZE];
bool cmp( const PStar &a, const PStar &b ) {
    return a.ps->x<b.ps->x || (a.ps->x==b.ps->x&&a.ps->y>b.ps->y) ;
}
void init() {
    for( int i=0; i<star_amount; ++i ) {
        scanf( "%d%d", &stars[i].x, &stars[i].y );
        stars[i].below = 0;
        pt[0][i].ps = stars+i;
    }
    sort( pt[0], pt[0]+star_amount, cmp );
}

void merge_sort() {
    PStar *fa, *fb;
    fa = pt[0]; fb = pt[1];
    for( int k = 1; k<star_amount; k<<=1 ) {
        int dk = 2*k;
        for( int ks=0; ks<star_amount; ks+=dk ) {
            int p, q, pi, qi, zi, left;
            pi = ks+k; qi = star_amount<(ks+dk)?star_amount:(ks+dk);
            left=0;
            zi = ks;
            for( p=ks, q=pi; p<pi&&q<qi; ) {
                if( fa[p]->y<fa[q]->y ||
                        fa[p]->y==fa[q]->y&&fa[p]->x==fa[q]->x ) {
                    fa[q]->below+=left;
                    fb[zi++] = fa[q++];
                }else {
                    ++left;
                    fb[zi++] = fa[p++];
                }
            }
            while( p<pi ) fb[zi++] = fa[p++];
            while( q<qi ) {
                fa[q]->below+=left;
                fb[zi++] = fa[q++];
            }
        }
        swap( fa, fb );
    }
}

int main() {
    while( EOF != scanf( "%d", &star_amount ) ) {
        init();
        merge_sort();
        for (int i=0; i<star_amount-1; ++i)
            printf( "%d ", stars[i].below );
        printf( "%d\n", stars[star_amount-1].below );
    }
}
