#include <cstdio>
#include <cmath>

int amount;
struct Point{
	int x, y;
};
Point pts[150];
char matrix[150][151];
double dist[150][150];
void init() {
	int i;
	scanf( "%d", &amount );
	for( i=0; i<amount; ++i )
		scanf( "%d%d", &pts[i].x, &pts[i].y );
	for( i=0; i<amount; ++i )
		scanf( "%s", matrix[i] );
}
double get_dist( int pa, int pb ) {
	double dx, dy;
	dx = pts[pa].x-pts[pb].x;
	dy = pts[pa].y-pts[pb].y;
	dx*=dx; dy*=dy;
	return sqrt(dx+dy);
}
const double LIMIT = 0x0fffffff;
void floyd() {
	int i, j, k;
	for( i=0; i<amount; ++i )
		for( j=0; j<amount; ++j )
		if( matrix[i][j]=='1' )
			dist[i][j] = get_dist(i,j);
		else dist[i][j] = LIMIT;
	for( k=0; k<amount; ++k )
		for( i=0; i<amount; ++i )
			for( j=0; j<amount; ++j ) {
				double dt;
				dt = dist[i][k]+dist[k][j];
				if( dt<dist[i][j] )
					dist[i][j] = dt;
			}
	for( i=0; i<amount; ++i ) dist[i][i]=0;
}
double ldist[150], dia[150], last;
void deal() {
	int i, j;
	last = LIMIT;
	for( i=0; i<amount; ++i )
		for( j=0; j<amount; ++j )
			if( dist[i][j] != LIMIT && dist[i][j]>ldist[i] )
				ldist[i] = dist[i][j];
	for( i=0; i<amount; ++i )
		for( j=0; j<amount; ++j )
			if( dist[i][j] != LIMIT && ldist[j]>dia[i] )
				dia[i]=ldist[j];
	for( i=0; i<amount; ++i )
		for( j=i+1; j<amount; ++j )
		if( dist[i][j]==LIMIT ) {
			double kt = 0, tmp;
			if( dia[i]>kt ) kt=dia[i];
			if( dia[j]>kt ) kt=dia[j];
			tmp = ldist[i]+ldist[j]+get_dist(i,j);
			if( tmp>kt ) kt=tmp;
			if( last>kt ) last = kt;
		}
	printf( "%.6lf", last );
}
int main() {
	init();
	floyd();
	deal();
	return 0;
}









