#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int mux[15][15], sz, remain;
bool used[15][15];
int retx[256], rety[256], rlen;
int dx[8]={ 2, 2,-2,-2, 1, 1,-1,-1};
int dy[8]={ 1,-1,-1, 1,-2, 2,-2, 2};

struct Point{
    short x, y;
};

bool isin (int x, int y) { return 0<=x&&x<sz && 0<=y&&y<sz; }

void chmod (int x, int y, bool inc=1) {
    for (int k=0; k<8; ++k) {
        int nx, ny;
        nx = x+dx[k];
        ny = y+dy[k];
        if (isin(nx,ny)) {
            if (inc) ++mux[nx][ny];
            else --mux[nx][ny];
        }
    }
}

void init() {
    remain = sz*sz;
    memset (used, 0, sizeof(used));
    memset (mux, 0, sizeof(mux));
    rlen = 0;
    for (int i=0; i<sz; ++i) 
        for (int j=0; j<sz; ++j)
            chmod (i, j);
}

bool cmp (const Point &pa, const Point &pb) {
    return mux[pa.x][pa.y]<mux[pb.x][pb.y];
}

void output() {
    for (int i=0; i<rlen; ++i)
        printf ("%c%c\n", \'a\'+retx[i], \'A\'+rety[i]);
}

void dfs (int nx, int ny) {
    retx[rlen] = nx;
    rety[rlen] = ny;
    ++rlen;
    chmod (nx, ny, 0);
    Point pn[8];
    --remain;
    used[nx][ny] = 1;

    if (remain==0) {
        output();
        exit(0);
    }
    int pl, lx, ly;
    pl = 0;
    for (int i=0; i<8; ++i) {
        lx = nx+dx[i];
        ly = ny+dy[i];
        if (isin(lx,ly) && used[lx][ly]==0 ) {
            pn[pl].x = lx;
            pn[pl].y = ly;
            ++pl;
        }
    }
    sort (pn, pn+pl, cmp);
    for (int i=0; i<pl; ++i)
        dfs (pn[i].x, pn[i].y);
    
    used[nx][ny] = 0;
    ++remain;
    chmod (nx, ny);
    --rlen;
}

int main() {
    scanf ("%d", &sz);
    init();
    dfs (0,0);
    puts ("IMPOSSIBLE");
}

