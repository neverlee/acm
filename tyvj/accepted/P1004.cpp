#include<cstdio>
#include<algorithm>
using namespace std;

int row, col;
int map[110][110];
struct Pos{
	char x,y;
} mps[10010];
bool Cmp( const Pos &a, const Pos &b ) {
	return map[a.x][a.y]>map[b.x][b.y];
}
const int UNLIMIT=2E8;
int res[110][110]={0};
char dx[]={-1,0,0,1};
char dy[]={0,-1,1,0};
int main() {
	scanf( "%d %d", &row, &col );
	for( int i=1,k=0; i<=row; ++i )
	for( int j=1; j<=col; ++j ) {
		scanf( "%d", map[i]+j );
		mps[k].x=i; mps[k].y=j;
		++k;
	}
	for( int i=0; i<=row+1; ++i ) map[i][0]=map[i][col+1]=UNLIMIT;
	for( int i=0; i<=col+1; ++i ) map[0][i]=map[row+1][i]=UNLIMIT;
	int iend=row*col;
	sort( mps, mps+iend, Cmp );
	for( int i=0; i<iend; ++i )
	for( int j=0; j<4; ++j ) {
		int ax, ay;
		ax=mps[i].x+dx[j]; ay=mps[i].y+dy[j];
		if( map[mps[i].x][mps[i].y]>map[ax][ay]
				&& res[mps[i].x][mps[i].y]+1>res[ax][ay] )
			res[ax][ay]=res[mps[i].x][mps[i].y]+1;
	}
	int ilast=0;
	for( int i=1; i<=row; ++i )
	for( int j=1; j<=col; ++j )
		ilast=ilast>res[i][j]?ilast:res[i][j];
	printf( "%d", ilast+1 );
}
	
