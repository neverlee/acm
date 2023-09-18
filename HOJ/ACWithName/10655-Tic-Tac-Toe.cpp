//10655-Tic-Tac-Toe.cpp
#include<cstdio>
#include<cstring>
char line[8][3]={
    0,1,2,
    3,4,5,
    6,7,8,
    0,3,6,
    1,4,7,
    2,5,8,
    0,4,8,
    2,4,6
};
char str[10], ix, io, h;
void Win() {
	h=0;
	for( int i=0; i<8; ++i ) {
		if( str[line[i][0]]==str[line[i][1]]
				&& str[line[i][1]]==str[line[i][2]]
				&& str[line[i][0]]!='.' )
			if( str[line[i][0]]=='X' ) ++h;
			else h+=4;
	}
}

int main(){
	while( gets(str) ) {
		if( strcmp( str, "end" )==0 ) break;
		ix=0;io=0;
		for( int i=0; i<9; ++i ) {
			if( str[i]=='X' ) ++ix;
			if( str[i]=='O' ) ++io;
		}
		Win();
		if(		  ( ix==io+1 && h>0 && h<4 )
				||( ix==io && h>3 && h%4==0 )
				||( ix==5 && io==4 && h==0 ) )
			puts("valid");
		else puts("invalid");
	}
}
