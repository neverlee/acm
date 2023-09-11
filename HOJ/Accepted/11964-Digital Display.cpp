// 11964-Digital Display.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

char num[7][60]={
"+---+    ++---++---++   ++---++---++---++---++---+ ",
"|   |    |    |    ||   ||    |        ||   ||   | ",
"|   |    |    |    ||   ||    |        ||   ||   |o",
"+   +    ++---++---++---++---++---+    ++---++---+ ",
"|   |    ||        |    |    ||   |    ||   |    |o",
"|   |    ||        |    |    ||   |    ||   |    | ",
"+---+    ++---++---+    ++---++---+    ++---++---+ "};

char result[7][31];
char str[10];
void SetResult()
{
	int s=0;
	for(int i=0;i<7;i++)
		for(int j=0;j<31;j++)
			result[i][j]=' ';
	for(int i=0;i<5;i++)
		if(i!=2)
		{
			str[i]-='0';
			for(int j=0;j<7;j++)
				for(int k=0;k<5;k++)
				{result[j][s+k]=num[j][str[i]*5+k];}
			s+=7;
		}
		else s+=3;
	result[2][14]=result[4][14]='o';
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<29;j++)
			putchar(result[i][j]);
		putchar('\n');
	}
	printf("\n\n");
}

int main()
{

	while(scanf("%s",str))
	{
		if(str[0]=='e'){printf("end\n");return 0;}
		SetResult();
	}
	return 0;
}

