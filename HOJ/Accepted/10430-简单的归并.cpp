// 10430-简单的归并.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

int la[1000],na,lb[1000],nb;
int main()
{
	freopen("E:\\ACMIn.txt","r",stdin);
	freopen("E:\\ACMOut.txt","w",stdout);
	int ncase;
	scanf("%ld",&ncase);
	while(ncase--)
	{
		scanf("%ld",&na);
		for(int i=0;i<na;i++)
			scanf("%ld",&la[i]);
		scanf("%ld",&nb);
		for(int i=0;i<nb;i++)
			scanf("%ld",&lb[i]);
		int x=0,y=0;
		if(la[x]>lb[y]){printf("%ld",lb[y]);y++;}
		else {printf("%ld",la[x]);x++;}
		while(x<na&&y<nb)
		{
			if(la[x]>lb[y]){printf(" %ld",lb[y]);y++;}
			else {printf(" %ld",la[x]);x++;}
		}
		for(;x<na;x++)
			printf(" %ld",la[x]);
		for(;y<nb;y++)
			printf(" %ld",lb[y]);
		putchar('\n');
	}
}

