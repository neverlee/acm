#include<cstdio>
#include<algorithm>
using namespace std;

int row, col, dr, dc, ren;
int rs[1001], cs[1001];
int imin( int a, int b ) { return a<b?a:b; }
void Init() {
	scanf( "%d %d %d %d %d", &row, &col, &dr, &dc, &ren );
	int ka,kb,kc,kd;
	while( ren-- ) {
		scanf( "%d %d %d %d", &ka, &kb, &kc, &kd );
		if( ka==kc ) ++cs[ imin(kb,kd) ];
		else ++rs[ imin(ka,kc) ];
	}
}
int *ay, srt[1001];
bool Cmp( const int &a, const int &b ) { return ay[a]>ay[b]; }
void Deal() {
	ay=rs;
	for( int i=0; i<=row; ++i ) srt[i]=i;
	sort( srt+1, srt+row+1, Cmp );
	if( dr!=0 ) {
		sort( srt+1, srt+dr+1 );
		for( int i=1; i<dr; ++i ) printf( "%d ", srt[i] );
		printf( "%d\n", srt[dr] );
	}else putchar('\n');
	ay=cs;
	for( int i=0; i<=col; ++i ) srt[i]=i;
	sort( srt+1, srt+col+1, Cmp );
	if( dc!=0 ) {
		sort( srt+1, srt+dc+1 );
		for( int i=1; i<dc; ++i ) printf( "%d ", srt[i] );
		printf( "%d\n", srt[dc] );
	}else putchar('\n');
}
int main() {
	Init();
	Deal();
}

