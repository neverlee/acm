#include<cstdio>
#include<cstring>
#include<queue>
#include<cctype>
using namespace std;
int p_amount, b_amount;
char name[21][90];
queue<int> ballot[1000];
int getint( char *&p ) {
	while( !isdigit(*p) ) ++p;
	int n = *p-'0';
	for( ++p; isdigit(*p); ++p )
		n = n*10+*p-'0';
	return n;
}
void input() {
	int i, j, k;
	scanf( "%d%*c", &p_amount );
	for( i=1; i<=p_amount; ++i )
		gets( name[i] );
	char str[1000];
	for( i=0; gets( str ); ++i ) {
		while( !ballot[i].empty() ) ballot[i].pop();
		if( str[0] == 0 ) {
			b_amount = i;
			break;
		}
		char *p = str;
		for( j=0; j<p_amount; ++j ) {
			k = getint( p );
			ballot[i].push(k);
		}
		str[0]=0;
	}
}
int get[21];
void countGet() {
	int i;
	memset( get, 0, sizeof(get) );
	for( i=0; i<b_amount; ++i )
		++get[ ballot[i].front() ];
}
void getmm( int &max, int &min ) {
	int i;
	max=0; min=2000;
	for( i=1; i<=p_amount; ++i ) {
		max = max>get[i]?max:get[i];
		if( get[i]>0 && min>get[i] ) min=get[i];
	}
}
void output() {
	int i;
	for( i=1; i<=p_amount; ++i )
	if( name[i][0]!=-1 )
		puts(name[i]);
}
void vote() {
	int i, j;
	for( i=1; i<=p_amount; ++i ) {
		countGet();
		int imax, imin;
		getmm( imax, imin );
		if( imax == imin ) {
			output();
			return;
		}
		if( imax*2>b_amount ) {
			for( j=1; j<=p_amount; ++j )
			if( get[j]!=imax ) name[j][0]=-1;
			output();
			return;
		}else{
			for( j=1; j<=p_amount; ++j )
			if( get[j]==imin ) name[j][0]=-1;
			for( j=0; j<b_amount; ++j )
				while( name[ ballot[j].front() ][0]==-1 )
					ballot[j].pop();
		}
	}
}
int main() {
	int iTest, i;
	scanf( "%d", &iTest );
	while( iTest-- ) {
		input();
		vote();
		if( iTest!=0 ) printf("\n");
	}
}