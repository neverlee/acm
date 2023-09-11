#include<cstdio>
char cube[6][8]={    "..+---+",
					 "./   /|",
					 "+---+ |",
					 "|   | +",
					 "|   |/.",
					 "+---+.." };

int row, col, map[50][50];
int height=0, width;
int imax( int a, int b ) { return a>b?a:b; }
void GetWidth() {
	width = 2*row+4*col+1;
}
void GetHeight( int x, int y ) {
	height = imax( height, map[x][y]*3+2*(row-x)+1 );
}
void Init() {
	scanf( "%d %d", &row, &col );
	GetWidth();
	for( int i=0; i<row; ++i )
		for( int j=0; j<col; ++j ) {
			scanf( "%d", map[i]+j );
			GetHeight( i, j );
		}
}
int str, stc;
void GetStart() {
	str = height-row*2+2-6;
	stc = row*2-2;
}
char rect[410][310];
void InitRect() {
	for( int i=0; i<height; ++i ) {
		for( int j=0; j<width; ++j )
			rect[i][j]='.';
		rect[i][width]=0;
	}
}
void Draw( int r, int c ) {
	for( int i=0; i<6; ++i )
		for( int j=0; cube[i][j]; ++j )
		if( cube[i][j] != '.' )
			rect[r+i][c+j]=cube[i][j];
}
void Do() {
	for( int i=0; i<row; ++i ) {
		int dr, dc, kc;
		dr = str+2*i;
		kc = stc-2*i;
		for( int j=0; j<col; ++j ) {
			dc = kc+4*j;
			for( int k=0; k<map[i][j]; ++k ) {
				int dlr=dr-k*3;
				Draw( dlr, dc );
			}
		}
	}
	for( int i=0; i<height; ++i ) puts( rect[i] );
}
int main() {
	Init();
	GetStart();
	InitRect();
	Do();
}
