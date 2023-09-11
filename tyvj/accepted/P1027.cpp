#include<cstdio>
int row, col, rect[45][45];
void init() {
	scanf ("%d%d", &row, &col);
	for (int i=1; i<=row; ++i)
		for (int j=1; j<=col; ++j)
			scanf ("%d", rect[i]+j);
	for (int i=0; i<=row+1; ++i)
		rect[i][0]=rect[i][col+1]=-1;
	for (int i=0; i<=col+1; ++i)
		rect[0][i]=rect[row+1][i]=-1;
}
int dx[]={-1, 0, 0, 1};
int dy[]={ 0,-1, 1, 0};
void go() {
	int px=1, py=1, get=0;
	while (px!=row||py!=col) {
		int best=0;
		for (int i=1; i<4; ++i) {
			if (rect[px+dx[best]][py+dy[best]]<rect[px+dx[i]][py+dy[i]])
				best=i;
		}
		get+=rect[px][py];
		rect[px][py]=0;
		px+=dx[best];
		py+=dy[best];
	}
	printf ("%d", get+rect[row][col]);
}
int main() {
	init();
	go();
}
