#include<cstdio>
#include<cstdlib>
#include<cstring>
const int BUF_SIZE = 10000;
char bfa[BUF_SIZE+10], bfb[BUF_SIZE+10];
FILE *fp1, *fp2;
int la,lb;
int iMin( int a, int b ) { return a<b?a:b; }
int Diff( char *fn1, char *fn2 ) {
	if( (fp1=fopen(fn1,"r"))==NULL ) {
		puts( "文件一不存在!" );
		return -1;
	}
	if( (fp2=fopen(fn2,"r"))==NULL ) {
		puts( "文件二不存在!" );
		fclose( fp1 );
		return -1;
	}
	int flag=1;
	while( fgets( bfa, BUF_SIZE, fp1 ) ) {
		fgets( bfb, BUF_SIZE, fp2 );
		la=strlen(bfa); lb=strlen(bfb);
		while( la>0&&(bfa[la-1]==13||bfa[la-1]==10) ) --la;
		while( lb>0&&(bfb[lb-1]==13||bfb[lb-1]==10) ) --lb;
		bfa[la]=bfb[lb]=0;
		if( (la-lb)*(la-lb)>1 ) {
			flag=0;
			break;
		}
		int l=iMin(la,lb);
		for( int i=0; i<l; ++i )
			if( bfa[i]!=bfb[i] ) {
				flag=0;
				break;
			}
	}
	fclose(fp1); fclose(fp2);
	return flag;
}

int main() {
	char sfa[100], sfb[100];
	for( int i=1; i<11; ++i ) {
		sprintf( sfa, "./out/output%d.txt", i );
		sprintf( sfb, "./Output/output%d.txt", i );
		printf( "%s\n", Diff( sfb, sfa )?"same":"diff" );
	}
}
