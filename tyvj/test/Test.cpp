#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

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

void Complier() {
	system( "rm cmain" ); 
	if( 0!=system( "g++ cmain.cpp -o cmain" ) ) {
		printf( " 编译错误！ \n" );
		exit( -2 );
	}else{
		puts( " 编译成功！" );
	}
}

void Running( int pid, int nid ) {
	char str[200];
	sprintf( str, "rm ./out/output%d.txt", nid );
	system( str );
	sprintf( str, "./cmain <./tyvjdb/P%d/Input/input%d.txt >./out/output%d.txt"
			, pid+1000, nid, nid );
	system( str );
	sprintf( str, "./out/output%d.txt", nid );
	FILE *fp;
	if( 0==( fp=fopen(str,"r") ) ) {
		printf( " 程序运行第 %d 组数据时出错！\n ", nid );
		sprintf( str, "rm ./out/output%d.txt", nid );
		system( str );
	}else {
		printf( " 运行第 %d 组数据完成！\n ", nid );
		fclose(fp);
	}
}

int pid;
void Test() {
	Complier();
	for( int i=0; i<11; ++i )
		Running( pid, i );
	
	int res[11]={0};
	char sf1[200], sf2[200];
	for( int i=0; i<11; ++i ) {
		sprintf( sf1, "./tyvjdb/P%d/Output/output%d.txt", pid+1000, i );
		sprintf( sf2, "./out/output%d.txt", i );
		res[i] = Diff( sf1, sf2 );
	}
	for( int i=0; i<11; ++i ) {
		printf( "Data %3d is ", i );
		if( res[i]==-1 ) puts( "not exist!" );
		if( res[i]==0 ) puts( "worry answer" );
		if( res[i]==1 ) puts( "accepted" );
	}
	//copy
	sprintf( sf1, "cp cmain.cpp code/P%d.cpp", pid+1000 );
	system( sf1 );
}

int main( int argc, char **argv ) {
	sscanf( argv[1], "%d", &pid );
	Test();
}
