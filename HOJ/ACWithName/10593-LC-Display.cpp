// 10593-LC-Display.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>
char bitNum[5][40]={
" -     -  -     -  -  -  -  - ",
"| |  |  |  || ||  |    || || |",
"       -  -  -  -  -     -  - ",
"| |  ||    |  |  || |  || |  |",
" -     -  -     -  -     -  - ",};
int size,len;
char str[100];

void PutOne(int num,int pos)
{
	int k=num*3;
	putchar(bitNum[pos][k]);
	for(int i=0;i<size;i++)
		putchar(bitNum[pos][k+1]);
	putchar(bitNum[pos][k+2]);
}
void PutLine(int pos)
{
	PutOne(str[0],pos);
	for(int i=1;i<len;i++)
	{putchar(' ');PutOne(str[i],pos);}
	putchar('\n');
}
void PutAll()
{
	PutLine(0);
	for(int i=0;i<size;i++)
		PutLine(1);
	PutLine(2);
	for(int i=0;i<size;i++)
		PutLine(3);
	PutLine(4);
	putchar('\n');
}

int main()
{
	while(scanf("%d %s",&size,str),1)
	{
		if(size==0)return 0;
		len=strlen(str);
		for(int i=0;i<len;i++)str[i]-='0';
		PutAll();
	}
}
