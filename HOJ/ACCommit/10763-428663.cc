#include <cstdio>
#include <cstring>

int dx[] = { 1 ,  1, -1, -1, -2, -2,  2, 2 };
int dy[] = { 2 , -2,  2, -2,  1, -1, -1, 1 };
int sx, sy, ret;
bool used[4][5];

bool isin( int x, int y ) {
    return x>=0 && x<=3 && y>=0 && y<=4;
}
void find( int rx, int ry ) {
    int nx, ny;
    used[rx][ry] = 1;
    for( int i=0; i<8; ++i ) {
        nx = rx+dx[i];
        ny = ry+dy[i];
        if( nx==sx && ny==sy ) ++ret;
        if( isin( nx, ny ) && !used[nx][ny] ) {
            find( nx, ny );
        }
    }
    used[rx][ry] = 0;
}

int main() {
    while( ~scanf( "%d%d", &sx, &sy ) ) {
        if( isin( sx, sy ) ) {
            ret = 0;
            memset( used, 0, sizeof( used ) );
            find( sx, sy );
            printf( "%d\n", ret );
        }else puts("Error !");
    }
}
