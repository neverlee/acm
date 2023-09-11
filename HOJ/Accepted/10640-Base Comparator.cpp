// 10640-Base Comparator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>
char num1[200],num2[200];int base1,base2;
int re1,re2;

int SetNum(char sn[],int &base)
{
	int len=strlen(sn);
	if(base==1)return len-1;
	int k=1,re=0;
	for(int i=len-1;i>=0;i--)
	{
		re+=(k*(sn[i]-'0'));k*=base;
	}
	return re;
}

int main()
{
	while(scanf("%s %d %s %d",num1,&base1,num2,&base2)!=EOF)
	{
		re1=SetNum(num1,base1);
		re2=SetNum(num2,base2);
		if(re1==re2){printf("=\n");continue;}
		if(re1<re2){printf("<\n");continue;}
		if(re1>re2){printf(">\n");continue;}
	}
	return 0;
}