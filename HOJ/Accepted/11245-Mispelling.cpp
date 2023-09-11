// 11245-Mispelling.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

int main()
{
	int ncase;
	scanf("%ld",&ncase);
	int num;char str[100];
	for(int text=0;text<ncase;text++)
	{
		scanf("%d %s",&num,str);
		printf("%d ",text+1);
		int i;
		for(i=0;str[i];i++)
			if(i!=num-1)
				putchar(str[i]);
		printf("\n");
	}
	return 0;
}