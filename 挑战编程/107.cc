#include<cstdio>
struct Point {
	char x,y;
};
Point knight[8] = {
	-2, -1,
	-2,  1,
	 2, -1,
	 2,  1,
	-1, -2,
	-1,  2,
	 1, -2,
	 1,  2
};
Point line[8] = {
	-1,  0,
	 1,  0,
	 0, -1,
	 0,  1,
	-1, -1,
	-1,  1,
	 1, -1,
	 1,  1
};
char board[20][20];
bool Check( char x, char y, char sy ) {
	char d;
	if( sy==0 ) d=1;
	else d=-1;
	if( board[x+d][y-1]=='P'+sy || board[x+d][y+1]=='P'+sy ) return 1;

	for( int i=0; i<8; ++i )
		if( board[x+knight[i].x][y+knight[i].y] == 'N'+sy ) return 1;

	for( int i=0; i<4; ++i ) {
		for( int k=1; (d=board[x+line[i].x*k][y+line[i].y*k]) =='.' ; ++k );
		if( d=='R'+sy || d=='Q'+sy ) return 1;
	}
	for( int i=4; i<8; ++i ) {
		for( int k=1; (d=board[x+line[i].x*k][y+line[i].y*k]) == '.' ; ++k );
		if( d=='B'+sy || d=='Q'+sy ) return 1;
	}
	return 0;
}
bool IsEmpty() {
	for( int i=4; i<12; ++i )
		for( int j=4; j<12; ++j )
			if( board[i][j] != '.' )
				return 0;
	return 1;
}
int main() {
	for( int T=1; 1 ; ++T ) {
		for( int i=4; i<12; ++i )
			gets( board[i]+4 );
		if( IsEmpty() ) break;
		char x,y,d=0;
		for( x=4; x<12; ++x )
		for( y=4; y<12; ++y )
			if( board[x][y]=='K' ){
				if( Check(x,y,32) ) d=1;
				break;
			}
		for( x=4; x<12; ++x )
		for( y=4; y<12; ++y )
			if( board[x][y]=='k' ){
				if( Check(x,y,0) ) d=3;
				break;
		}
		switch( d ) {
		case 3:
			printf( "Game #%ld: black king is in check.\n", T );
			break;
		case 1:
			printf( "Game #%ld: white king is in check.\n", T );
			break;
		default:
			printf( "Game #%ld: no king is in check.\n", T );
		}
		gets( board[0] );
	}
}