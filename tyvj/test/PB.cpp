#include<cstdlib>
#include<cstdio>
#include<cstring>
void Read( int num ) {
	char str[200], *ps, *pe;
	sprintf( str, "enconv .//tyvjdb//P%d/", 1000+num );
	ps=str+3; pe=str+strlen(str);
	strcpy( pe, "*.txt" );
	system( str );
	
	puts( "---------------------------------------------------" );
	strcpy( ps, "cat" ); str[6]=' ';
	printf( "＊＊＊背景＊＊＊\n" );
	strcpy( pe, "Background.txt" );
	system( ps );
	putchar('\n');
	printf( "＊＊＊描述＊＊＊\n" );
	strcpy( pe, "Description.txt" );
	system( ps );
	putchar('\n');
	printf( "＊＊＊输入格式＊＊＊\n" );
	strcpy( pe, "InputFormat.txt" );
	system( ps );
	putchar('\n');
	printf( "＊＊＊输出格式＊＊＊\n" );
	strcpy( pe, "OutputFormat.txt" );
	system( ps );
	putchar('\n');
	printf( "＊＊＊时间限制＊＊＊\n" );
	strcpy( pe, "TimeLimitation.txt" );
	system( ps );
	putchar('\n');
	printf( "＊＊＊输入样例：\n" );
	strcpy( pe, "SampleInput.txt" );
	system( ps );
	putchar('\n');putchar('\n');
	printf( "＊＊＊输出样例：\n" );
	strcpy( pe, "SampleOutput.txt" );
	system( ps );
	putchar('\n');
	printf( "＊＊＊其他＊＊＊\n" );
	strcpy( pe, "Hint.txt" );
	system( ps );
}

int main( int argc, char **argv ) {
	int num;
	sscanf( argv[1], "%d", &num );
	Read( num );
}
