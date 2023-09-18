#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

#define X(n) ((n)&0xffff)
#define Y(n) ((n)>>16)
#define G(x,y) ((x)|((y)<<16))

int p[1300]={2}, pamount=1;
bool is_prime( int tn ) {
    if( tn==1 ) return 0;
    int ie = (int)sqrt((double)tn);
    for( int i=0; ie>=p[i]; ++i )
        if( tn%p[i]==0 ) return 0;
    return 1;
}
void init_prime() {
    for( int i=3; i<10020; i+=2 )
        if( is_prime(i) )
            p[pamount++] = i;
}

int isz, mut[110][110];
void input() {
    memset( mut, 0, sizeof(mut) );
    int t;
    for( int i=1; i<=isz; ++i )
        for( int j=1; j<=isz; ++j ) {
            scanf( "%d", &t );
            if( is_prime( t ) ) mut[i][j]=2;
            else mut[i][j]=4;
        }
}

void bfs() {
    int uni, non, ay[5000], rr;
    uni = non = 0;
    const int dx[] = {-1, 0, 0, 1};
    const int dy[] = { 0,-1, 1, 0};
    for( int i=1; i<=isz; ++i )
        for( int j=1; j<=isz; ++j )
        if( mut[i][j]>1 ) {
            int area = 1;
            rr = mut[i][j];
            mut[i][j] = 0;
            queue<int> qi;
            qi.push( G(i,j) );
            while( !qi.empty() ) {
                int px, py, nx, ny;
                px = X(qi.front());
                py = Y(qi.front());
                qi.pop();
                for( int i=0; i<4; ++i ) {
                    nx = px+dx[i];
                    ny = py+dy[i];
                    if( mut[nx][ny]==rr ) {
                        mut[nx][ny] = 0;
                        ++area;
                        qi.push( G(nx,ny) );
                    }
                }
            }
            if( rr==2 ) ay[uni++] = area;
            else ++non;
        }
    sort( ay, ay+uni );
    printf( "%d unique vegetation regions:", uni );
    for( int i=0; i<uni; ++i ) printf( " %d", ay[i] );
    puts("");
    printf( "%d non-unique vegetation regions\n", non );
}

int main() {
    init_prime();
    for( int T=1; scanf( "%d", &isz ), isz>0; ++T ) {
        input();
        printf( "Area %d:\n", T );
        bfs();
    }
}
