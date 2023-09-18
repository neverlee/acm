#include <cstdio>
#include <cmath>

bool grid[110][210];
int high, amount;

void init() {
    scanf( "%d%d", &high, &amount );
    int x, y, t;
    for( int i=0; i<amount; ++i ) {
        scanf( "%d", &t );
        x = sqrt((double)(t-1));
        y = t-x*x;
        ++x;
        grid[x][y] = 1;
    }
}

void work() {
    int yl, cnt;
    yl = 2*high;
    cnt = 0;
    for( int i=1; i<=high; ++i ) {
        for( int j=1; j<yl; ++j )
        if( grid[i][j] ) {
            cnt += grid[i][j-1] + grid[i][j+1];
            if( i%2&&j%2 || i%2==0&&j%2 ) cnt += grid[i+1][j+1];
            else cnt += grid[i-1][j-1];
        }
    }
    printf( "%d", 3*amount-cnt );
}

int main() {
    init();
    work();
}
