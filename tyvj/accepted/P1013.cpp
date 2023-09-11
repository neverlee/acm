#include<cstdio>
struct {
	int num, time;
}f[110][110];
int arp, armb;
int amount,rmb[100],rp[100],time[100];

void Input() {
	scanf( "%d", &amount );
	for( int i=0; i<amount; ++i )
		scanf( "%d %d %d", rmb+i, rp+i, time+i );
	scanf( "%d %d", &armb, &arp );
}

void Dp() {
	f[0][0].num=1;
	for( int i=0; i<amount; ++i ) {
		int nm, nr;
		for( int m=armb; (nm=m-rmb[i])>=0; --m ) {
			for( int r=arp; (nr=r-rp[i])>=0; --r ) {
				if( f[nm][nr].num>0 &&
						( f[nm][nr].num>=f[m][r].num ||
						  ( f[nm][nr].num+1>=f[m][r].num &&
							f[nm][nr].time+time[i]<=f[m][r].time ) ) ) {
					f[m][r].num=f[nm][nr].num+1;
					f[m][r].time=f[nm][nr].time+time[i];
				}
			}
		}
	}
	int inum=1, iti=0;
	for( int i=0; i<=armb; ++i )
		for( int j=0; j<=arp; ++j )
			if( f[i][j].num>inum ||
					( f[i][j].num==inum && f[i][j].time<iti ) ) {
				inum=f[i][j].num;
				iti=f[i][j].time;
			}
	printf( "%d", iti );
}

int main() {
	Input();
	Dp();
}

