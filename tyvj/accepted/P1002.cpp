#include<cstdio>
#include<cstring>
char slast[100];
int ilast, itotal;
char name[100]; int avg, clg; char gb, xb; int lw;
int main() {
	int xss;
	scanf( "%d", &xss );
	ilast=itotal=0;
	while( xss-- ) {
		scanf( "%s %d %d %c %c %d", name, &avg, &clg, &gb, &xb, &lw );
		int get=0;
		if( avg>80 && lw>0 ) get+=8000;
		if( avg>85 && clg>80 ) get+=4000;
		if( avg>90 ) get+=2000;
		if( avg>85 && xb=='Y' ) get+=1000;
		if( clg>80 && gb=='Y' ) get+=850;
		itotal+=get;
		if( get>ilast ) {
			strcpy( slast, name );
			ilast=get;
		}
	}
	printf( "%s\n%d\n%d\n", slast, ilast, itotal );
}
