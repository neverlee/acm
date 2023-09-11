//10370-虫食算.cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int nhex;
char exp[3][40];
int *order[40];
int ref[40];
bool used[40];
int mode[40];//-1无效，0无进位，1有进位
void init() {
	int i, j;
	scanf( "%d", &nhex );
	scanf( "%s%s%s", exp[0], exp[1], exp[2] );
	for( i=0; i<3; ++i ) {
		reverse( exp[i], exp[i]+nhex );
		for( j=0; exp[i][j]; ++j ) exp[i][j]-='A';
	}
}

void get_order() {
	int i, j, k;
	bool used[40]={0};
	for( i=0, k=0; i<nhex; ++i )
		for( j=0; j<3; ++j ) {
			if( used[ exp[j][i] ] == 0 ) {
				used[ exp[j][i] ] = 1;
				order[k++] = ref+exp[j][i];
			}
		}
}

bool check() {
	int i, j, k;
	for( i=0; i<nhex; ++i ) {
		int ia[3];
		int m=-1;
		for( j=0; j<3; ++j )
			ia[j] = ref[exp[j][i]];
		if( ia[0]!=-1 && ia[1]!=-1 && ia[2]!=-1 ) {
			k = ia[0]+ia[1]+mode[i];
			if( k/nhex==1 ) m = 1;
			else m=0;
			if( ia[2]!=k%nhex )
				return false;
		}else break;
		mode[i+1]=m;
	}
	for( ; i<nhex; ++i ) {
		int cs, cr;
		cs = cr = 0;
		int ia[3];
		for( j=0; j<3; ++j )
			ia[j] = ref[exp[j][i]];
		if( ia[0]!=-1 && ia[1]!=-1 && ia[2]!=-1 ) {
			k = ia[0]+ia[1];
			if( k%nhex!=ia[2] && (k+1)%nhex!=ia[2] )
				return false;
		}else if( ia[0]!=-1 && ia[1]!=-1 ) {
			k = ia[0]+ia[1];
			if( used[k%nhex] && used[(k+1)%nhex] )
				return false;
		}else if( (ia[0]!=-1||ia[1]!=-1) && ia[2]!=-1 ) {
			k = ia[0]+ia[1]+1;
			ia[2]+=nhex;
			if( used[(ia[2]-k)%nhex] && used[(ia[2]-k-1)%nhex] )
				return false;
		}
		if( i==nhex-1 && ia[0]+ia[1]+1>=nhex ) return false;
	}
	return true;
}

void dfs( int lv ) {
	int i;
	if( lv>=nhex ) {
		for( i=0; i<nhex; ++i ) {
			if( i ) putchar(' ');
			printf( "%d", ref[i] );
		}
		//output();
		exit(0);
		//return;
	}
	for( i=0; i<nhex; ++i )
	if( used[i]==0 ) {
		*(order[lv]) = i;
		used[i]=1;
		if( check() )
			dfs( lv+1 );
		used[i]=0;
	}
	*(order[lv]) = -1;
}

void find() {
	memset( ref, -1, sizeof(ref) );
	memset( used, 0, sizeof(used) );
	memset( mode, -1, sizeof(used) );
	mode[0]=0;
	dfs( 0 );
}

int main() {
	init();
	get_order();
	find();
	return 0;
}
