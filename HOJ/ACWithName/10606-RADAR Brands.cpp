// 10606-RADAR Brands.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>

char num[1050];
int len,i;

bool isPd()
{
	for(i=0;i<len-i-1;i++)
		if(num[i]!=num[len-i-1])
			return 0;
	return 1;
}

void InWei()
{
	for(i=0;i<len-1;i++)
	{num[i+1]+=num[i]/10;num[i]%=10;}
	if(num[len-1]>9)
	{num[len]=num[len-1]/10;num[len-1]%=10;++len;}
}

void Add()
{
	char c;
	for(i=0;i<=len-i-1;i++)
		num[i]=num[len-i-1]=num[i]+num[len-i-1];
	InWei();
}

int main()
{
	int ncase;char str[1050];
	gets(num);len=strlen(num);
	strcpy(str,num);
	int i;
	for(i=0;i<len;i++)num[i]-='0';
	if(isPd()){printf("0 %s\n",str);return 0;}
	for(i=1;;i++)
	{
		Add();
		if(isPd())
		{
			printf("%ld ",i);
			for(int j=0;j<len;j++)
				putchar(num[j]+'0');
			putchar('\n');
			break;
		}
	}
	return 0;
}

