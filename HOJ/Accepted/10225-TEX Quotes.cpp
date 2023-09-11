// 10225-TEX Quotes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
int main()
{
	char c;
	bool isLeft = 1;
	while((c=getchar())!=-1)
	{
		if(c=='\"')
		{
			if(isLeft)
			{printf("``");isLeft=0;}
			else
			{printf("\'\'");isLeft=1;}
		}
		else
			putchar(c);
	}
	return 0;
}